#include <unistd.h>

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

int main()
{
	unsigned char octet = 3;
	reverse_bits(octet);
	print_bits(octet);
	write(1, "\n", 1);

}