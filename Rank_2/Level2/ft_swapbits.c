#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return (octet << 4 | octet >> 4);
}

void	print_bits(unsigned char octet)
{
	unsigned char bit;
	int i = 7;

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
	unsigned char rev;
	print_bits(octet);
	write(1, "\n", 1);
	rev = swap_bits(octet);
	print_bits(rev);
	write(1, "\n", 1);

}