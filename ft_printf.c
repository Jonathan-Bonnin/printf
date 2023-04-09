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

int decide_what_to_print(const char *format, va_list args);
int print_one_char(char c);
int print_string(char *c);
int print_unsigned_int(unsigned int n);
int print_signed_int(int n);
int print_hex(long unsigned int n, const char *hex_chars);

int	ft_printf(const char *format, ...)
{
	int 	total_chars_printed;
	va_list	args;
	// comparison vs printf regarding number of chars printed
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
	if (*format == 'c')
		return (print_one_char(va_arg(args, int))); 
	if (*format == 's')
		return (print_string(va_arg(args, char*)));
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
	if (*format == 'p')
	{
		char* hex_val = "0123456789abcdef";
		print_string("0x");
		return (2 + print_hex(va_arg(args, long unsigned int), hex_val));
	}
}

int print_one_char(char c)
{
    write(1, &c, 1);
    return (1);
}

int print_string(char *c)
{
    int i;

    i = 0;
    while (c[i])
    {
        write(1, &c[i], 1);
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