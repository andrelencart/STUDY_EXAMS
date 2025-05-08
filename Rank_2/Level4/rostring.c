#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int j = 0;

	if (ac == 2)
	{
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == 9))
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == 9)
				break;
			i++;
		}
		i++;
		j = i;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == 9)
			{
				while (av[1][i] == ' ' || av[1][i] == 9)
					i++;
				write(1, " ", 1);	
			}
			write(1, &av[1][i], 1);
			i++;
		}
		i = 0;
		while (av[1][i] || av[1][i] == ' ' || av[1][i] == 9)
			i++;
		while (av[1][i] || av[1][i] == ' ' || av[1][i] == 9)
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
}