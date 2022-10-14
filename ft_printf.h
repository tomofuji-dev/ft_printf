/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:11:04 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/10/14 16:49:28 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_print_char(int c);
int	ft_print_string(const char *s);
int	ft_print_percent(void);
int	ft_print_unsigned_int(unsigned int ui);
int	ft_print_int(int i);
int	ft_print_pointer(unsigned long long ln);
int	ft_print_hex(unsigned int n, char flag);
int	ft_printf(const char *format, ...);

#endif	/* FT_PRINTF_H */