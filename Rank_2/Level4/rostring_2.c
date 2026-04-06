#include <unistd.h>
#include <stdlib.h>


void	put_word(char *str, int i)
{
	while(str[i] && (str[i] != ' ' || str[i] != 9))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int	i = 0;
	int j = 0;

	if (ac == 2)
	{
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == 9))
			i++;
		j = i;
		while(av[1][j] && (av[1][j] != ' ' || av[1][j] != 9))
			j++;
		while(av[1][j])
		{
			if (av[1][j] && (av[1][j] != ' ' || av[1][j] != 9) && (av[1][j - 1] == ' ' || av[1][j - 1] == 9))
			{
				while(av[1][j] && (av[1][j] == ' ' || av[1][j] == 9))
				{
					write(1, &av[1][j], 1);
					j++;
				}
				write(1, " ", 1);
			}
			j++;
		}
		put_word(av[1], j);
		// while (av[1][i])
		// {
		// 	if (av[1][i] == ' ' || av[1][i] == 9)
		// 		break;
		// 	i++;
		// }
		// j = i;
		// j--;
		// while (av[1][i] && (av[1][i] == ' ' || av[1][i] == 9))
		// 	i++;
		// while (av[1][i])
		// {
		// 	if (av[1][i] == ' ' || av[1][i] == 9)
		// 	{
		// 		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == 9))
		// 			i++;
		// 		write(1, " ", 1);
		// 	}
		// 	write(1, &av[1][i], 1);
		// 	i++;
		// }
		// // write(1, &av[1][j], 1);
		// while (av[1][j] && (av[1][j] != ' ' || av[1][j] != 9))
		// 	j--;
		// j++;

		// while (av[1][j] && (av[1][j] != ' ' || av[1][j] != 9))
		// {
		// 	write(1, &av[1][j], 1);
		// 	j++;
		// }
	}
	write(1, "\n", 1);
}