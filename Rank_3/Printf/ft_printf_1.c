
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	putstr(char *s)
{
	int	i = 0;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

long ft_strlen(char *s)
{
	long len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

int unputnbr_base(unsigned int n, char *base)
{
	unsigned int result = 0;
	size_t len = ft_strlen(base);
	char	c;

	if (n >= len)
	{
		result +=  unputnbr_base(n / len, base);
		result +=  unputnbr_base(n % len, base);
	}
	else
	{
		c = base[n];
		result += write(1, &c, 1);
	}
	return (result);
}

int putnbr_base(int nb, char *base)
{
	int result = 0;
	long len = ft_strlen(base);
	char	c;
	long n = nb;

	if(n < 0)
	{
		result += write(1, "-", 1);
		n *= -1;
	}
	if (n >= len)
	{
		result +=  putnbr_base(n / len, base);
		result +=  putnbr_base(n % len, base);
	}
	else
	{
		c = base[n];
		result += write(1, &c, 1);
	}
	return (result);
}

int printf_rules(char c, va_list list)
{
	int	print = 0;

	if (c == 's')
		print += putstr(va_arg(list, char *));
	else if (c == 'd')
		print += putnbr_base(va_arg(list, int), "0123456789");
	else if (c == 'x')
		print += unputnbr_base(va_arg(list, unsigned int), "0123456789abcdef");
	return (print);
}

int ft_printf(const char *s, ... )
{
	int i = 0;
	va_list arg;
	int print = 0;

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
	return(print);
}
int	main(void)
{
	int				d = INT_MIN - 1;
	char			*str = "";
	unsigned int	x = 0;
	
	printf("pstring: %s\n", str);
	ft_printf("string: %s\n", str);

	printf("pdigit: %d\n", d);
	ft_printf("digit: %d\n", d);

	printf("pLhexdecimal: %x\n", x);
	ft_printf("Lhexdecimal: %x\n", x);

}
