#include <unistd.h>
#include <limits.h>

int	ft_atoi(char *str)
{
	int res = 0;
	int	sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	ft_putnbr(int n)
{
	char res;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		res = n + '0';
		write(1, &res, 1);
	}
}
int	main(int ac, char **av)
{
	int	i = 1;
	int	nbr;

	if (ac == 2)
	{
		nbr = ft_atoi(av[1]);
		while (i <= 9 && nbr <= (INT_MAX / 9))
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);
			write(1, "\n", 1);
			i++;
		}
	}
}