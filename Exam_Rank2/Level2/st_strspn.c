#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i = 0;
	int	len = 0;

	while (*s)
	{
		while (accept[i] && accept[i] != *s)
			i++;
		if (accept[i] == '\0')
			return (len);
		i = 0;
		len++;
		s++;
	}
	return (len);
}

int	main(void)
{
	printf("%s\n", strspn("aaabcd", "abcdb"));
	printf("mine: %s\n", ft_strspn("aaabcd", "abcd"));
}