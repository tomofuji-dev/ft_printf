/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:30:30 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/14 11:23:59 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digits(unsigned int i)
{
	unsigned int	count;

	count = 1;
	while (i / 10 > 0)
	{
		count += 1;
		i /= 10;
	}
	return (count);
}

static unsigned int	power_of_ten(unsigned int i)
{
	unsigned int	power;		

	power = 1;
	while (i-- > 0)
		power *= 10;
	return (power);
}

int	ft_print_unsigned_int(unsigned int ui)
{
	unsigned int	count;
	unsigned int	power;
	int				digit;

	count = count_digits(ui);
	power = power_of_ten(count - 1);
	while (count-- > 0)
	{
		digit = (ui / power) % 10;
		power /= 10;
		ft_print_char('0' + digit);
	}
	return (count);
}

int	ft_print_int(int i)
{
	int				print_size;
	unsigned int	ui;

	print_size = 0;
	if (i < 0)
	{
		ft_print_char('-');
		print_size++;
		ui = -i;
	}
	else
		ui = i;
	print_size += ft_print_unsigned_int(ui);
	return (print_size);
}
