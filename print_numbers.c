/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:28:21 by jbonnin           #+#    #+#             */
/*   Updated: 2023/04/10 13:30:52 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned_int(unsigned int n)
{
	if (n < 10)
		return (print_one_char(n + '0'));
	return (print_unsigned_int(n / 10) + print_one_char((n % 10) + '0'));
}

int	print_signed_int(int n)
{
	if (n < 0)
	{
		print_one_char('-');
		return (1 + print_unsigned_int(-n));
	}
	if (n < 10)
		return (print_one_char(n + '0'));
	return (print_unsigned_int(n / 10) + print_one_char((n % 10) + '0'));
}

int	print_hex(long unsigned int n, const char *hex_chars)
{
	if (n < 16)
		return (print_one_char(hex_chars[n]));
	return (print_hex(n / 16, hex_chars) + print_one_char(hex_chars[n % 16]));
}
