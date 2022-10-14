/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:30:30 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/14 15:44:15 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digits(unsigned int n)
{
	unsigned int	count;

	count = 1;
	while (n / 10 > 0)
	{
		count += 1;
		n /= 10;
	}
	return (count);
}

static unsigned int	power_of_ten(unsigned int exponent)
{
	unsigned int	power;		

	power = 1;
	while (exponent-- > 0)
		power *= 10;
	return (power);
}

int	ft_print_unsigned_int(unsigned int un)
{
	unsigned int	count;
	unsigned int	power;
	unsigned int	digit;

	count = count_digits(un);
	power = power_of_ten(count - 1);
	while (count-- > 0)
	{
		digit = (un / power) % 10;
		power /= 10;
		ft_print_char('0' + digit);
	}
	return (count);
}

int	ft_print_int(int n)
{
	int				print_size;
	unsigned int	un;

	print_size = 0;
	if (n < 0)
	{
		ft_print_char('-');
		print_size++;
		un = -n;
	}
	else
		un = n;
	print_size += ft_print_unsigned_int(un);
	return (print_size);
}
