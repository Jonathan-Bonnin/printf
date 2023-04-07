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
#include <stdarg.h>
#include "print_numbers.c"

int decide_what_to_print(const char *c, va_list args);

int	ft_printf(const char *format, ...)
{
	int 	total_chars_printed;
	va_list	args;
	// handle pxX, double check %
	// comparison vs printf
	// return nb of chars printed
	// va_arg: everytime it is called, it modifies argument_list so that the next time it is called
	// it will return the next argument

	// va_list
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

int decide_what_to_print(const char *c, va_list args)
{
	if (*c == 'c')
		return (print_one_char(va_arg(args, int))); 
	if (*c == 's')
		return (print_string(va_arg(args, char*)));
	if (*c == 'p') // pointer adr
		return (0);
	if (*c == 'd' || *c == 'i')
		return (print_signed_int(va_arg(args, int)));
	if (*c == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int)));
	if (*c == 'x') // unsigned hexadecimal int
		return (0);
	if (*c == 'X') // unsigned hexadecimal int (capital letter)
		return (0);
	if (*c == '%')
		return (print_percent_sign());
}