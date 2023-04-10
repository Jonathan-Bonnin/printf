/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:33:55 by jbonnin           #+#    #+#             */
/*   Updated: 2023/04/10 13:28:29 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		total_chars_printed;
	va_list	args;

	va_start(args, format);
	total_chars_printed = 0;
	while (*format)
	{
		if (*format == '%')
			total_chars_printed += decide_what_to_print(++format, args);
		else
		{
			write(1, format, 1);
			total_chars_printed++;
		}
		format++;
	}
	va_end(args);
	return (total_chars_printed);
}

int	decide_what_to_print(const char *format, va_list args)
{
	char				*hex;
	long unsigned int	ptr;

	if (*format == 'c')
		return (print_one_char(va_arg(args, int)));
	if (*format == 's')
		return (print_str(va_arg(args, char *)));
	if (*format == 'd' || *format == 'i')
		return (print_signed_int(va_arg(args, int)));
	if (*format == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int)));
	if (*format == 'x')
		return (print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (*format == 'X')
		return (print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (*format == '%')
		return (print_one_char('%'));
	hex = "0123456789abcdef";
	ptr = va_arg(args, long unsigned int);
	if (!ptr)
		return (print_str("(nil)"));
	return (print_str("0x") + print_hex(ptr, hex));
}

int	print_one_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *c)
{
	int	i;

	if (!c)
		return (print_str("(null)"));
	i = 0;
	while (c[i])
	{
		print_one_char(c[i]);
		i++;
	}
	return (i);
}
