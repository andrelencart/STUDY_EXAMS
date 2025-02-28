#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int	biggest = 0;
	int	i = 0;

	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > biggest)
			biggest = tab[i];
		i++;
	}
	return (biggest);
}

int main()
{
	int int_tab[] = {1, -3, 2, 10, 10};
	printf("%d\n", max(int_tab, 5));
}