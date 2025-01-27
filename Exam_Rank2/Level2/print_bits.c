#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char bit;

	while (i >= 0)
	{
		bit = octet >> i & 1;
		write(1, &"01"[bit], 1);
		i--;
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 0;
	unsigned char bit = 0;

	while (i < 8)
	{
		bit += octet >> i & 1;
		if (i < 7)
			bit = bit << 1;
		i++; 
	}
	return (bit);
}