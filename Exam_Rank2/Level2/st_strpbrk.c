#include <string.h>
#include <stdio.h>


char	*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		while (*s2)
		{
			if (*s1 == *s2)
				return (s1);
			s1++;
		}
		s2++;
	}
	return (NULL);
}

int	main(void)
{
	printf("%s\n", strpbrk("ear", "abcdb"));
	printf("mine: %s\n", ft_strpbrk("ear", "abcdb"));
}