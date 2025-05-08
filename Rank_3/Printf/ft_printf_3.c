
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int	putstrf(char *s)
{
	int	i = 0;
	int print = 0;

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
	return (print);
}

long ft_len(char *s)
{
	long len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

int	unputnbr_base(unsigned int n, char *base)
{
	int print = 0;
	long len = ft_len(base);
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
	int print = 0;
	long n = nb;
	long len = ft_len(base);
	char c;

	if (n < 0)
	{
		print += write(1, "-", 1);
		n *= -1;
	}
	if (n >= len)
	{
		print += putnbr_base(n / len, base);
		print += putnbr_base(n % len, base);
	}
	else
	{
		c = base[n];
		print += write(1, &c, 1);
	}
	return (print);
}

int	printf_rules(char c, va_list list)
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

int	ft_printf(const char *s, ...)
{
	int	i = 0;
	va_list arg;
	int	print = 0;

	va_start(arg, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			print += printf_rules(s[++i], arg);
		else
			print += write(1, &s[i], 1);
		i++;
	}
	va_end(arg);
	return (print);
}

int	main(void)
{
	int	d = INT_MIN;
	char *s = NULL;
	unsigned int x = INT_MAX;

	printf("d: %d s: %s x: %x u know \n", d, s, x);
	ft_printf("d: %d s: %s x: %x u know \n", d, s, x);

	printf("Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);

	printf("Magic %s is %d\n", "number", 42);
	ft_printf("Magic %s is %d\n", "number", 42);

	printf("%s\n", (char*)0);
	ft_printf("%s\n", NULL);
}