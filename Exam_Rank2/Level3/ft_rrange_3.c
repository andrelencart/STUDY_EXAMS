#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int	len = end - start;
	int *range;
	int i = 0;

	if (len < 0)
		len = -len;
	len++;
	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	while (i < len)
	{
		if (start < end)
		{
			range[i] = end;
			end--;
			i++;
		}
		else	
		{
			range[i] = end;
			end++;
			i++;
		}
	}
	return (range);
}

int	main(void)
{
	int	end = -3;
	int start = 0;
	int	 *arr = ft_rrange(start, end);
	int	i = 0;

	while (start >= end)
	{
		printf("%d, ", arr[i]);
		i++;
		start--;
	}

}