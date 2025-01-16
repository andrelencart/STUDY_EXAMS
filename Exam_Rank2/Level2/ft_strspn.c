#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	len = 0;
	size_t	i = 0;

	while (*s)
	{
		while (accept[i] && *s != accept[i])
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
	printf("%ld\n", strspn("aabc", "abcdb"));
	printf("mine: %ld\n", ft_strspn("aabc", "abcdb"));
}