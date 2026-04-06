#include <unistd.h>

long	ft_atoi(char *s)
{
	int	i = 0;
	long res = 0;
	
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return(res);
}

void ft_putnbr(long n)
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
	long n = 0;

	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		
		n = ft_atoi(av[1]);
		// if (n > __INT_MAX__)
		// 	return (0);
		while (i <= 9 &&  n <= __INT32_MAX__ / 9 )
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(i * n);
			write(1, "\n", 1);
			i++;
		}
	}
}