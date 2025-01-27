#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int	ft_len(long n)
// {
// 	int	len = 0;

// 	if (n < 0)
// 	{
// 		n = -n;
// 		len++;
// 	}
// 	if (n == 0)
// 		len++;
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_itoa(int nbr)
// {
// 	long n = nbr;
// 	long	len = ft_len(n);
// 	char *str;

// 	str = malloc(sizeof(char *) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	str[len] = '\0';
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		n = -n;
// 	}
// 	if (n == 0);
// 		str[0] = '0';
// 	while (len >= 0 && n > 0)
// 	{
// 		str[--len] = (n % 10) + '0';
// 		n /= 10;
// 	}
// 	return (str);
// }

int	ft_len(long n)
{
	long len = 0;

	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long n = nbr;
	long len = ft_len(n);
	char *str;

	str = malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	while (len >= 0 && n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", itoa(123));
	printf("mine :%s\n", ft_itoa(__INT_MAX__));
}