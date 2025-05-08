#include <unistd.h>

int main(int ac, char **av)
{
	int i = 1;

	while (i < ac)
	{
		int j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 'A' && av[i][j] <= 'Z' && av[i][j + 1] != ' ' && av[i][j + 1] != 9 && av[i][j + 1] != '\0')
				av[i][j] += 32;
			else if ((av[i][j + 1] == ' ' || av[i][j + 1] == 9 || av[i][j + 1] == '\0') && av[i][j] >= 'a' && av[i][j] <= 'z')
				av[i][j] -= 32;
			write (1, &av[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}