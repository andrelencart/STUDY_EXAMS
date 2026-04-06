/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:48:19 by andcarva          #+#    #+#             */
/*   Updated: 2025/01/27 18:38:23 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char res;
	
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		res = n + '0';
		write(1, &res, 1);	
	}
}

int	ft_atoi(char *s)
{
	int	res = 0;
	while (*s != '\0')
	{
		res = res * 10 + (*s - '0');
		s++; 
	}
	return (res);
}

int	ft_prime(int i)
{
	int n = 2;

	if (i <= 1)
		return (0);
	while (n < i)
	{
		if ((i % n) == 0)
			return (0);
		n++;
	}
	return (1);
}

int	prime_add(int nbr)
{
	int	i = 2;
	int sum = 0;
	
	if (nbr <= 0)
		return (0);
	while (i <= nbr)
	{
		if (ft_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int ac, char **av)
{
	int	nbr;
	int	res;
	if(ac != 2 || av[1] < 0)
	{
		write(1, "0\n", 2);
	}
	else
	{
		nbr = ft_atoi(av[1]);
		res = prime_add(nbr);
		ft_putnbr(res);
		write(1, "\n", 1);
	}
}