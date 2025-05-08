#include <unistd.h>

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

int	ft_atoi(char *s)
{
	int res = 0;

	while (*s && *s >= '0' && *s <= '9')
	{
		res = res  * 10 + (*s - '0');
		s++;
	}
	return (res);
}

int	ft_prime(int n)
{
	int	i = 2;

	if (n <= 1)
		return (0);
	while(n > i)
	{
		if ((n % i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	nbr;
	int sum = 0;

	if (ac != 2 || ft_atoi(av[1]) <= 0)
		write(1, "0\n", 2);
	else
	{
		nbr = ft_atoi(av[1]);
		while (nbr > 1)
		{
			if (ft_prime(nbr))
				sum += nbr;
			nbr--;
		}
		ft_putnbr(sum);
		write(1, "\n", 1);
	} 
}
