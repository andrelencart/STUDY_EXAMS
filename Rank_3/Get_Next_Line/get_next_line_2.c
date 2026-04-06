
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 10
#endif

void	buffer_move(char *buffer)
{
	int i = 0;
	int j = 0;

	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[j] != '\0')
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

size_t ft_linelen(char *s)
{
	size_t len = 0;

	while (s && s[len] && s[len] != '\n')
		len++;
	if (s && s[len] == '\n')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int	i = 0;
	int	j = 0;

	newstr = malloc(sizeof(char) * ((ft_linelen(s1) + ft_linelen(s2) + 1)));
	if (!newstr)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		newstr[i + j++] = '\n';
	newstr[i + j] = '\0';
	free(s1);
	return (newstr);
}


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		buffer_move(buffer);
		len = ft_linelen(line);
		if (line[len - 1] == '\n')
			return (line);
	}
	return (line);
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	char  *line;

	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			printf("line: %s", line);
			free(line);
		}
		else
			break;
	}
}