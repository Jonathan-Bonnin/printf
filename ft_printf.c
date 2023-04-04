/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:33:55 by jbonnin           #+#    #+#             */
/*   Updated: 2023/04/02 16:10:57 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int total_chars_printed;
	// handle pxX
	// comparison vs printf
	// return nb of chars printed
	// va_start, va_arg, va_copy, va_end
	total_chars_printed = 0;
	while (*format) 
	{
		write(1, format, 1);
		format++;
		total_chars_printed++;
	}
	return (total_chars_printed);
}

int decide_what_to_print(char c, va_list to_print)
{
	if (c == 'c')
		return (print_one_char(to_print)); 
	if (c == 's')
		return (print_string(to_print));
	if (c == 'p') // pointer adr
		return (0);
	if (c == 'd' || c == 'i')
		return (print_signed_int(to_print));
	if (c == 'u')
		return (print_unsigned_int(to_print));
	if (c == 'x') // unsigned hexadecimal int
		return (0);
	if (c == 'X') // unsigned hexadecimal int (capital letter)
		return (0);
	if (c == '%')
		return (print_percent_sign());
}