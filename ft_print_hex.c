/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:10:25 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/16 08:27:14 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	count_digits_hex(unsigned long long n)
{
	unsigned int	count;

	count = 1;
	while (n / 16 > 0)
	{
		count += 1;
		n /= 16;
	}
	return (count);
}

static unsigned long long	power_of_hex(unsigned int exponent)
{
	unsigned long long	power;		

	power = 1;
	while (exponent-- > 0)
		power *= 16;
	return (power);
}

static int	ft_print_hex_unsigned_ll(unsigned long long ln, char flag)
{
	unsigned int		count;
	unsigned long long	power;
	unsigned int		digit;
	unsigned int		i;

	count = count_digits_hex(ln);
	power = power_of_hex(count - 1);
	i = 0;
	while (i++ < count)
	{
		digit = (ln / power) % 16;
		power /= 16;
		if (digit < 10)
			ft_print_char('0' + digit);
		else
		{
			if (flag == 'x')
				ft_print_char('a' + digit - 10);
			else if (flag == 'X')
				ft_print_char('A' + digit - 10);
		}
	}
	return (count);
}

int	ft_print_pointer(unsigned long long ln)
{
	ft_print_string("0x");
	return (ft_print_hex_unsigned_ll(ln, 'x') + 2);
}

int	ft_print_hex(unsigned int n, char flag)
{
	return (ft_print_hex_unsigned_ll(n, flag));
}
