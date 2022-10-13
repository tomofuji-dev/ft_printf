/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:58:19 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/14 08:32:00 by tfujiwar         ###   ########.fr       */
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
	if (**format_p == 'c')
		printf_size += ft_print_char(va_arg(ap, int));
	else if (**format_p == 's')
		printf_size += ft_print_string(va_arg(ap, (const char *)));
	else if (**format_p == 'p')
		printf_size += ft_print_pointer(va_arg(ap, (void *)));
	else if (**format_p == 'd' || **format_p == 'i')
		printf_size += ft_print_int(va_arg(ap, int));
	else if (**format_p == 'u')
		printf_size += ft_print_unsigned_int(va_arg(ap, unsigned int));
	else if (**format_p == 'x' || **format_p == 'X')
		printf_size += ft_print_hex(va_arg(ap, unsigned int), **format_p);
	else if (**format_p == '%')
		printf_size += ft_print_percent();
	return (0);
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
			print_size += print_plain(&(format++));
		else
			print_size += print_convert(&format, ap);
	}
	va_end(ap);
	return (print_size);
}

int	main(void)
{
	ft_printf("abc%abc\n");
	ft_printf("%ba\n");
}
