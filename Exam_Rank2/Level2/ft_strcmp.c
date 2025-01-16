#include <string.h>
#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] -  s2[i]);
}

/* int	ft_strcmp(char *s1, char *s2)
{
	while(*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return(*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
} */

#include <stdio.h>

/* int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
} */	

int	main(void)
{
	printf("%d\n", strcmp("abc", "ab"));
	printf("mine: %d\n", ft_strcmp("abc", "ab"));
}