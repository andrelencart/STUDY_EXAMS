#!/bin/bash
# Behavior tests for mini_serv. Usage: bash test_mini_serv.sh [file.c]   (default: mini_serv.c)
# Needs: gcc, python3. Runs the real server and talks to it with real sockets.

SRC="${1:-mini_serv.c}"
TMP=$(mktemp -d)
BIN="$TMP/mini_serv"
PORT=$((20000 + RANDOM % 20000))
FAILS=0
SERVER=""

cleanup() { [ -n "$SERVER" ] && kill "$SERVER" 2>/dev/null; wait 2>/dev/null; rm -rf "$TMP"; }
trap cleanup EXIT

ok()   { echo -e "\033[0;32mPASS\033[0m $1"; }
ko()   { echo -e "\033[0;31mFAIL\033[0m $1"; FAILS=$((FAILS + 1)); }
check() { if [ "$2" = "$3" ]; then ok "$1"; else ko "$1"; echo "     expected: $(printf %q "$3")"; echo "     got:      $(printf %q "$2")"; fi; }

start_server() {
	"$BIN" "$PORT" > "$TMP/server_out" 2> "$TMP/server_err" &
	SERVER=$!
	sleep 0.3
}

echo "== Build =="
if gcc -Wall -Wextra -Werror "$SRC" -o "$BIN" 2> "$TMP/cc"; then ok "compiles with -Wall -Wextra -Werror"; else ko "compiles"; cat "$TMP/cc"; exit 1; fi
if grep -q '#define' "$SRC"; then ko "no #define (found one)"; else ok "no #define"; fi

echo "== Arguments and errors =="
# Exact stderr bytes, trailing \n included ($(...) alone would strip it, hence the "|" end marker).
check_err() {
	"$BIN" "${@:3}" > "$TMP/o" 2> "$TMP/e"; rc=$?
	check "$1: stderr exact, incl. newline" "$(cat "$TMP/e"; echo '|')" "$(printf "$2"; echo '|')"
	check "$1: exit code" "$rc" "1"
	check "$1: stdout empty" "$(cat "$TMP/o")" ""
}
check_err "no argument" 'Wrong number of arguments\n'
check_err "too many arguments" 'Wrong number of arguments\n' "$PORT" extra
start_server
check_err "port in use" 'Fatal error\n' "$PORT"

echo "== Chat behavior =="
python3 - "$PORT" <<'EOF' || FAILS=$((FAILS + $?))
import socket, sys, time
P = int(sys.argv[1]); fails = 0

def conn():
    s = socket.create_connection(('127.0.0.1', P)); s.settimeout(0.3); time.sleep(0.2); return s

def read(s):  # everything that arrives until 0.3s of silence
    data = b''
    while True:
        try:
            d = s.recv(65536)
            if not d: break
            data += d
        except socket.timeout: break
    return data.decode()

def check(name, got, want):
    global fails
    if got == want: print("\033[0;32mPASS\033[0m", name)
    else:
        fails += 1; print("\033[0;31mFAIL\033[0m", name); print("     expected:", repr(want)); print("     got:     ", repr(got))

a = conn(); b = conn()
check("client 0 told client 1 arrived", read(a), "server: client 1 just arrived\n")
check("new client gets no arrival msg for itself", read(b), "")
c = conn()
check("arrival reaches all old clients (0)", read(a), "server: client 2 just arrived\n")
check("arrival reaches all old clients (1)", read(b), "server: client 2 just arrived\n")

c.send(b'hel'); time.sleep(0.2); c.send(b'lo\nlonger line\nx\n'); time.sleep(0.3)
want = "client 2: hello\nclient 2: longer line\nclient 2: x\n"
check("partial line joined + prefix on every line + no leftovers (0)", read(a), want)
check("partial line joined + prefix on every line + no leftovers (1)", read(b), want)
check("sender gets nothing back", read(c), "")

c.close(); time.sleep(0.3)
check("leave reaches others (0)", read(a), "server: client 2 just left\n")
check("leave reaches others (1)", read(b), "server: client 2 just left\n")

a.send(b'hi\n'); time.sleep(0.2)
check("message after someone left", read(b), "client 0: hi\n")
d = conn()
check("ids never reused (next is 3)", read(a), "server: client 3 just arrived\n")

# A low fd gets freed and reused: maxfd must not drop, clients on higher fds must still work.
e = conn(); read(b); read(d)
a.close(); time.sleep(0.3); read(b); read(d); read(e)
f = conn()   # gets a's old fd, the lowest one
check("reused low fd: higher clients still get arrivals", read(b), "server: client 5 just arrived\n")
e.send(b'yo\n'); time.sleep(0.2)
check("reused low fd: higher clients still send/receive", read(b), "client 4: yo\n")
sys.exit(fails)
EOF

echo "== Lazy client + flood =="
python3 - "$PORT" <<'EOF' || FAILS=$((FAILS + 1))
import socket, sys, time, threading
P = int(sys.argv[1]); N = 20000
lazy = socket.create_connection(('127.0.0.1', P))           # connects, never reads
lazy.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 1024)
good = socket.create_connection(('127.0.0.1', P)); good.settimeout(10)
got = []
def reader():
    buf = b''
    try:
        while b'LAST' not in buf:
            d = good.recv(65536)
            if not d: break
            buf += d
    except socket.timeout: pass
    got.append(buf)
t = threading.Thread(target=reader); t.start(); time.sleep(0.3)
f = socket.create_connection(('127.0.0.1', P))
for i in range(N): f.sendall(b'flood line %d\n' % i)
f.sendall(b'LAST\n'); t.join()
n = got[0].count(b'flood line')
if n == N and b'LAST' in got[0]: print("\033[0;32mPASS\033[0m good client got all %d lines while a lazy client blocks" % N)
else: print("\033[0;31mFAIL\033[0m good client got %d/%d lines" % (n, N)); sys.exit(1)
EOF
if kill -0 "$SERVER" 2>/dev/null; then ok "server still alive"; else ko "server died"; exit 1; fi
kill "$SERVER"; wait "$SERVER" 2>/dev/null; SERVER=""

echo "== fd leaks =="
start_server
before=$(ls /proc/$SERVER/fd | wc -l)
for i in $(seq 1 30); do
	python3 -c "import socket;s=socket.create_connection(('127.0.0.1',$PORT));s.sendall(b'a\nhalf');s.close()"
done
sleep 0.5
after=$(ls /proc/$SERVER/fd | wc -l)
check "30 connect/disconnect leave no fd open ($before before)" "$after" "$before"
check "server prints nothing on stdout" "$(cat "$TMP/server_out")" ""

echo "=========================================="
if [ "$FAILS" -eq 0 ]; then echo -e "\033[0;32mALL PASSED\033[0m"; else echo -e "\033[0;31m$FAILS FAILED\033[0m"; fi
exit $((FAILS > 0))
