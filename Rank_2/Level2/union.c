#include <unistd.h>

int	check_d(char *str, char c, int pos)
{
	int	i = 0;

	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_doub(char *str, char c)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!check_d(av[1], av[1][i], i))
			{
				write(1, &av[1][i], 1);
			}
			i++;
		}
		int	j = 0;
		while (av[2][j])
		{
			if (!check_doub(av[1], av[2][j]))
			{
				if (!check_d(av[2], av[2][j], j))
					write(1, &av[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
}