#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	unsigned int	i = 0;

	while (i < n)
	{
		if (i * i == n)
		{
			printf("%d é o quadrardo perfeito de %d\n", n, i);
			return (1);
		}
		i++;
	}
	printf("%d não é o quadrardo perfeito\n", n);
	return (0);
}


int	main(void)
{
	printf("%d\n", is_power_of_2(9));
}