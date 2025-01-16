#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len = 0;
	size_t	i = 0;

	while (*s)
	{
		while (reject[i] && *s != reject[i])
			i++;
		if (reject[i] == '\0')
			return (len);
		i = 0;
		len++;
		s++;
	}
	return (len);
}

int	main(void)
{
	printf("%ld\n", strcspn("", "a"));
	printf("mine: %ld\n", ft_strcspn("", "a"));
}