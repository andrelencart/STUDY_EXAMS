#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		while (av[1][i] == ' ' || av[1][i] == 9)
				i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == 9)
			{
				if (av[1][i + 1] > ' ' && av[1][i + 1] != '\0')
					write(1, " ", 1);
			}
			else if (av[1][i] != ' ' && av[1][i] != 9)
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}