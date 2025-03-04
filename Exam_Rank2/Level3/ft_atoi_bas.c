#include <stdlib.h>
#include <stdio.h>

int	is_valid(int ch, int base)
{
	char *lwc = "0123456789abcdef";
	char *upc = "0123456789ABCDEF";
	int i = 0;

	while (i < base)
	{
		if (ch == lwc[i] || ch == upc[i])
			return(1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_bas)
{
	int	i = 0;
	int res = 0;
	int sign = 1;

	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		res *= str_bas;
		if (str[i] >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += str[i] - 'W';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += str[i] - '7';
		i++;
	}
	return (res * sign);
}
 
int	main(void)
{

	printf("%d\n", ft_atoi_base("1", 16));
}