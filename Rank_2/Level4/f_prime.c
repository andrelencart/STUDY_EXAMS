#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{	
	int n = 0;
	int	i = 2;
	if (ac == 2)
	{
		n = atoi(av[1]);
		while (i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n != i)
					printf("*");
				n /= i;
			}
			else
				i++;
		}
	}
	printf("\n");
}