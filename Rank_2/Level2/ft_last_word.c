#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i = 0;
	char *str = av[1];

	if (ac == 2)
	{
		while (str[i])
			i++;
		while (str[i] == ' ' || str[i] == 9 || str[i] == '\0')
			i--;
		while (str[i] >= 33 && str[i] <= 126)
			i--;
		i++;
		while (str[i] >= 33 && str[i] <= 126)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

// int main (int ac, char **a)
// {
// 	if (ac == 2)
// 	{
// 		int i = 0;

// 		// getting to the end of the string
// 		while (a[1][i])
// 			i++;
// 		i--;
// 		// looping over the whole string backwards
// 		// until we found a space
// 		while (a[1][i] > 32)
// 			i--;
// 		i++;
// 		// getting back to the end and writing the last word to
// 		// the screen
// 		while (a[1][i])
// 		{
// 			write(1, &a[1][i], 1);
// 			i++;
// 		}
// 	}
// 	write (1, "\n", 1);
// }