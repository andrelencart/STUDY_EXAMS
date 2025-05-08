/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrlencart <andrlencart@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:43:34 by andrlencart       #+#    #+#             */
/*   Updated: 2025/02/25 15:15:41 by andrlencart      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mputnbr(int n)
{
	char	result;
	
	if (n > 9)
	{
		mputnbr(n / 10);
		mputnbr(n % 10);
	}
	else
	{
		result = n + '0';
		write(1, &result, 1);
	}
}

int	main(void)
{
	int	n = 1;
	
	while (n <= 100)
	{
		if (n % 5 == 0 && n % 3 == 0)
			write (1, "fizzbuzz", 8);
		else if (n % 5 == 0)
			write (1, "buzz", 4);
		else if (n % 3 == 0)
			write (1, "fizz", 4);
		else
			mputnbr(n);
		write(1, "\n", 1);
		n++;
	}
}