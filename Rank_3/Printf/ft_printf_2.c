
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int	putstrf(char *s)
{
	int	print = 0;
	int i = 0;

	if (!s)
	{
		print += write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		print += write(1, &s[i], 1);
		i++;
	}
	return (i);
}

long	len_base(char *s)
{
	long len = 0;

	while (s[len])
		len++;
	return (len);
}

int	unputnbr_base(unsigned int n, char *base)
{
	int	print = 0;
	long len = len_base(base);
	char c;

	if (n >= len)
	{
		print += unputnbr_base(n / len, base);
		print += unputnbr_base(n % len, base);
	}
	else
	{
		c = base[n];
		print += write(1, &c, 1);
	}
	return (print);
}

int	putnbr_base(int nb, char *base)
{
	int	print = 0;
	long n = nb;
	long len = len_base(base);
	char c;

	if (n < 0)
	{
		print += write(1, "-", 1);
		n *= -1;
	}
	if (n >= len)
	{
		print += unputnbr_base(n / len, base);
		print += unputnbr_base(n % len, base);
	}
	else
	{
		c = base[n];
		print += write(1, &c, 1);
	}
	return (print);
}

int	print_rules(char c, va_list list)
{
	int	print = 0;
	
	if (c == 's')
		print += putstrf(va_arg(list, char *));
	else if (c == 'd')
		print += putnbr_base(va_arg(list, int), "0123456789");
	else if (c == 'x')
		print += unputnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	return (print);
}

int ft_printf(const char *s, ... )
{
	int	print = 0;
	int	i = 0;
	va_list arg;

	va_start(arg, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			print += print_rules(s[++i], arg);
		else
			print += write(1, &s[i], 1);
		i++;
	}
	va_end(arg);
	return (print);
}

int	main(void)
{
	int	d = -0;
	char *s = NULL;
	unsigned int x = 14;

	printf("d: %d\n", d);
	ft_printf("d: %d\n", d);
	printf("s: %s\n", s);
	ft_printf("s: %s\n", s);
	printf("x: %x\n", x);
	ft_printf("x: %x\n", x);
}