#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const av[], int type)
{
	int	fd[2];
	int	pid;
	
	if (!file || !av || (type != 'r' && type != 'w'))
		return (-1);
	if (pipe(fd) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		exit(-1);
	}
	if (pid == 0)
	{
		if (type == 'r'){
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				exit(-1);
		}
		else{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) < 0)
				exit(-1);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, av);
		exit(-1);
	}
	if (type == 'r'){
		close(fd[1]);
		return (fd[0]);
	}
	else{
		close(fd[0]);
		return (fd[1]);
	}
}

int	main(){

	int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'w');

	char buf[1];
	while(read(fd, buf, 1))
		write(1, buf, 1);
	close(fd);
	return (0);
}