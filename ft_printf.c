/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:33:55 by jbonnin           #+#    #+#             */
/*   Updated: 2023/04/09 17:50:45 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int 	total_chars_printed;
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

int decide_what_to_print(const char *format, va_list args)
{
	char* hex;
	
	if (*format == 'c')
		return (print_one_char(va_arg(args, int))); 
	if (*format == 's')
		return (print_str(va_arg(args, char*)));
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
	return (print_str("0x") + print_hex(va_arg(args, long unsigned int), hex));
}

int print_one_char(char c)
{
    write(1, &c, 1);
    return (1);
}

int print_str(char *c)
{
    int i;

    i = 0;
    while (c[i])
    {
        print_one_char(c[i]);
        i++;
    }
    return(i);
}

int print_unsigned_int(unsigned int n)
{
    if(n < 10)
        return(print_one_char(n + '0'));
    print_unsigned_int(n / 10);
    return (1 + print_one_char((n % 10) + '0'));
}

int print_signed_int(int n)
{
    if (n < 0)
    {
        print_one_char('-');
        return (1 + print_unsigned_int(-n));
    }
    return (print_unsigned_int(n));
}

int print_hex(long unsigned int n, const char *hex_chars)
{
    if (n < 16)
        return (print_one_char(hex_chars[n]));
    print_hex(n / 16, hex_chars);
    return (1 + print_one_char(hex_chars[n % 16]));
}