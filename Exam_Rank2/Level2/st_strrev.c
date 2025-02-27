#include <string.h>
#include <stdio.h>

char    *ft_strrev(char *str)
{
	int	i = 0;
	int len = 0;
	int loop = 0;
	char tmp;

	while (str[len])
		len++;
	loop = len / 2;
	while (i < loop)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}

// char    *ft_strrev(char *str)
// {
// 	int i;
// 	int len;
// 	char tmp;


// 	i = 0;
// 	len = 0;
// 	while (str[len])
// 		len++;
// 	while (i < len - 1)
// 	{
// 		tmp = str[i];
// 		str[i] = str[len - 1];
// 		str[len - 1] = tmp;
// 		i++;
// 		len--;
// 	}
// 	return (str);
// }

int	main(void)
{
	char s[] = "wq";
	ft_strrev(s);
	printf("%s\n", s);
	return (0);
}