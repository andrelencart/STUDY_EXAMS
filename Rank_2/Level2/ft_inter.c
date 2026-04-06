#include <unistd.h>

int	ft_double(char *str, int pos, char c)
{
	int i = 0;

	while (i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int i = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			int	j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && !ft_double(av[1], i, av[1][i]))
				{
					write(1, &av[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}