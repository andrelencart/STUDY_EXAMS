#include <stdlib.h>

char    *ft_strdup(char *src)
{
	char *dup;
	int	i = 0;
	int len = 0;

	while (src[len])
		len++;
	dup = malloc(sizeof(char *) * (len + 1));
	if (!dup)
		reutrn (NULL);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}