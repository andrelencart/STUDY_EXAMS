#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i = 0;
	int signal = 1;
	int res = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if(str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signal);
}

int	main(void)
{
	printf("%d\n", atoi("  -42"));
	printf("mine: %d\n", ft_atoi(" -42"));
}