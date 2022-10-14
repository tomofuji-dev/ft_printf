/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:58:19 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/14 15:47:01 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	print_plain(const char **format_p)
{
	const char	*start;
	int			print_size;

	print_size = 0;
	start = *format_p;
	while (**format_p && **format_p != '%')
		(*format_p)++;
	write(1, start, *format_p - start);
	print_size += *format_p - start;
	return (print_size);
}

static int	print_convert(const char **format_p, va_list ap)
{
	int	print_size;

	print_size = 0;
	(*format_p)++;
	if (**format_p == 'c')
		print_size += ft_print_char(va_arg(ap, int));
	else if (**format_p == 's')
		print_size += ft_print_string(va_arg(ap, const char *));
	else if (**format_p == 'p')
		print_size += ft_print_pointer(va_arg(ap, unsigned long long));
	else if (**format_p == 'd' || **format_p == 'i')
		print_size += ft_print_int(va_arg(ap, int));
	else if (**format_p == 'u')
		print_size += ft_print_unsigned_int(va_arg(ap, unsigned int));
	else if (**format_p == 'x' || **format_p == 'X')
		print_size += ft_print_hex(va_arg(ap, unsigned int), **format_p);
	else if (**format_p == '%')
		print_size += ft_print_percent();
	(*format_p)++;
	return (print_size);
}

int	ft_printf(const char *format, ...)
{
	int		print_size;
	va_list	ap;

	print_size = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			print_size += print_plain(&format);
		else
			print_size += print_convert(&format, ap);
	}
	va_end(ap);
	return (print_size);
}

// int	main(void)
// {
// 	char	*pp;
// 	char	p;

// 	p = 'a';
// 	pp = &p;

// 	ft_printf("abc%cd%se%df%u%%\n", '1', "2345", -2147483648, 2147483647);
// 	ft_printf("%p||%x||%X\n", pp, 2147483647, 2147483647);
// }
