#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *s)
{
	int	i = 0;
	int res = 0;

	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

void	putnbr_base(int n, int nbr, char *base)
{
	char res;
	// int	count = 0;

	if (n >= nbr)
	{
		putnbr_base(n / nbr, nbr, base);
		putnbr_base(n % nbr, nbr, base);
	}
	else
	{
		res = base[n];
		write (1, &res, 1);
	}
}

int	main(int ac, char **av)
{
	int	nhex = 0;
	char *hex = "0123456789abcdef";

	if (ac == 2)
	{
		nhex = ft_atoi(av[1]);
		putnbr_base(nhex, 16, hex);
	}
	write (1, "\n", 1);
}