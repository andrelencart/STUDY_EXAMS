#include <unistd.h>

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
	print_bits(octet);
	write(1, "\n", 1);
}