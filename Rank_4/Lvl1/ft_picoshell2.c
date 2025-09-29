#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int picoshell(char **cmds[])
{
	int	i = 0;
	int	fd[2];
	int	res;
	int	pid;
	int	status;

	while (cmds[i]){
		if (cmds[i + 1])
		{
			if (pipe(fd) < 0)
				return 1;
		}
		pid = fork();
		if (pid < 0)
		{
			if (fd[0] >= 0)
				close(fd[0]);
			if (fd[1] >= 0)
				close(fd[1]);
			return 1;
		}
		if (pid == 0)
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], 1) < 0)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else{
			if (cmds[i + 1])
			{
				close(fd[1]);
				if (dup2(fd[0], 0) < 0)
					exit(1);
				close(fd[0]);
			}
		}
		i++;
	}
	while(wait(&status) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			res = 1;
		else if (!WIFEXITED(status))
			res = 1;
	}
	return (res);
}

int main(void)
{
    // Example: ls -l | grep main | wc -l
    // Each command is an array of arguments, ending with NULL
    char *cmd1[] = {"ls", "-l", NULL};
    char *cmd3[] = {"wc", "-l", NULL};

    // Array of pointers to each command array, ending with NULL
    char **cmds[] = {cmd1,  cmd3, NULL};

    int result = picoshell(cmds);
    if (result == 0)
        printf("All commands executed successfully.\n");
    else
        printf("One or more commands failed.\n");
    return result;
}