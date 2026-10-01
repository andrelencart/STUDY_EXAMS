#include <sys/select.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_clients
{
	int id;
	char msg[1000000];
} t_clients;

t_clients clients[1024];
fd_set current, read_set, write_set;
int maxfd, sockfd, next_id;
char recvbuf[4096];
char sendbuf[1000050];

void fatal(void){
	write(2, "Fatal error\n", 12);
	exit(1);
}

void broadcast(int except){
	for(int fd = 0; fd <= maxfd; fd++){
		if (FD_ISSET(fd, &write_set) && fd != except && fd != sockfd)
			send(fd, sendbuf, strlen(sendbuf), MSG_NOSIGNAL);
	}
}

int main(int ac, char **av) {

	if (ac != 2){
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0) { 
		fatal();
	}

	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr)); 

	// assign IP, PORT 
	addr.sin_family = AF_INET; 
	addr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	addr.sin_port = htons(atoi(av[1]));
	// Binding newly created socket to given IP and verification 
	if (bind(sockfd, (const struct sockaddr *)&addr, sizeof(addr)) < 0 || listen(sockfd, 128) < 0) { 
		fatal();
	}
	FD_ZERO(&current);
	FD_SET(sockfd, &current);
	maxfd = sockfd;

	while(1) {
		read_set = write_set = current;
		if (select(maxfd + 1, &read_set, &write_set, NULL, NULL) < 0)
			continue;
		for(int fd = 0; fd <= maxfd; fd++){
			if (!FD_ISSET(fd, &read_set))
				continue;
			
			if (fd == sockfd){
				int cfd = accept(sockfd, NULL, NULL);
				if (cfd < 0)
					continue;
				if (cfd > maxfd)
					maxfd = cfd;
				clients[cfd].id = next_id++;
				clients[cfd].msg[0] = 0;
				FD_SET(cfd, &current);
				sprintf(sendbuf, "server: client %d just arrived\n", clients[cfd].id);
				broadcast(cfd);
				continue;
			}

			int ret = recv(fd, recvbuf, sizeof(recvbuf), 0);
			if (ret <= 0){
				sprintf(sendbuf, "server: client %d just left\n", clients[fd].id),
				broadcast(fd);
				FD_CLR(fd, &current);
				FD_CLR(fd, &write_set);
				close(fd);
				continue;
			}

			int j = strlen(clients[fd].msg);
			for(int i = 0; i < ret; i++){
				clients[fd].msg[j++] = recvbuf[i];
				if (recvbuf[i] == '\n'){
					clients[fd].msg[j] = 0;
					sprintf(sendbuf, "client %d: %s", clients[fd].id, clients[fd].msg);
					broadcast(fd);
					j = 0;
				}
			}
			clients[fd].msg[j] = 0;
		}
	}
}