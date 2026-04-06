

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
