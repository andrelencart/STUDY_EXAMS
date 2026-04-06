#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int	ft_len(long n)
{
	int len = 0;

	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int	len = ft_len(nbr);
	char *s;

	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		s[0] = '0';
	while (nbr > 0 && len >= 0)
	{
		s[--len] = (nbr % 10) + '0';
		nbr /= 10; 
	}
	return (s);
}

int main(void)
{
	printf("%s\n", ft_itoa(-123));
}