#include <unistd.h>

void	print_bits(unsigned char octet)
{
	 int i = 7;
	unsigned char bit;

	while (i >= 0)
	{
		bit = octet >> i & 1;
		write (1, &"01"[bit], 1);
		i--;
	}
}

int main(void)
{
	print_bits(1);
}