#include <stdio.h>
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int i = 1;
	unsigned int hcf = 0;

	while (i <= a || i <= b)
	{
		if (a % i == 0 && b % i == 0)
			hcf = i;
		i++;
	}
	return (a * (b / hcf));
}

int main(void)
{
	printf("%d\n", lcm(5, 3));
}