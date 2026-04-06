#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int n1, n2, n = 0;

	if (ac == 3)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[2]);
		if (n1 > n2)
		{
			n = n2;
			while (n1 % n != 0 || n2 % n != 0)
				n--;
		}
		if (n2 > n1)
		{
			n = n1;
			while (n1 % n != 0 || n2 % n != 0)
				n--;
		}
		printf("%d", n);
	}
	printf("\n");
}