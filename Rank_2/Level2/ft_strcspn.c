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
		if (reject[i] != '\0')
			return (len);
		i = 0;
		len++;
		s++;
	}
	return (len);
}

// size_t ft_strcspn(const char *s, const char *reject)
// {
//     size_t i;
//     size_t j;
    
//     i = 0;
//     // Looping over the whole string
//     while(s[i++])
//     {
//         j = 0;
//         // Check the current string char against every char in charset
//         while (reject[j])
//         {
//             // If character found, return index in current string
//             if (s[i] == reject[j++])
//             	return (i);
//         }
//     }
//     // If we spanned the whole string, return i, in that case the
//     // rejected char found is the NULL-terminating one
//     return (i);
// }

void ft(char *str)
{
	int i = 0;

	while (str[i])
	{
		printf("%d\n", str[i]);
		i++;
	}

}

int	main(void)
{
	char *str2 =  "Hello";
	char *str1 =  "wihlho";

	ft(str1);
	printf("\n");
	ft(str2);

	printf("\n");
	printf("%ld\n", strcspn(str1, str2));
	printf("mine: %ld\n", ft_strcspn(str1, str2));
}