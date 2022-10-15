/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:43:04 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/16 08:37:05 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(const char *s)
{
	int	print_size;

	print_size = 0;
	if (!s)
		return (ft_print_string("(null)"));
	while (*s)
	{
		print_size += ft_print_char(*s);
		s++;
	}
	return (print_size);
}

int	ft_print_percent(void)
{
	return (ft_print_char('%'));
}
