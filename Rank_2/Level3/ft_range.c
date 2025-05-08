#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int	*range;
	int	len = end - start;
	int i = 0;

	if (len < 0)
		len = -len;
	len++;
	range = malloc(sizeof(int) * len);
	if (!range)
		return(NULL);
	while (i < len)
	{
		if (start < end)
		{
			range[i] = start;
			start++;
			i++;
		}
		else
		{
			range[i] = start;
			start--;
			i++;
		}
	}
	return(range);
}

int	main(void)
{
	int	end = 2;
	int start = -1;
	int	 *arr = ft_range(start, end);
	int	i = 0;

	while (start <= end)
	{
		printf("%d\n", arr[i]);
		i++;
		start++;
	}
}