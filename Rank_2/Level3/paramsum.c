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
		res = n + '0';
0	write(1, &res, 1);
}

int	main(int ac, char **av)
{
	(void)av;
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
}