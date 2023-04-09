/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:25:01 by jbonnin           #+#    #+#             */
/*   Updated: 2023/04/02 16:04:37 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_chars.c"

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

int print_hex(int n, const char *hex_chars)
{
    if (n < 16)
        return (print_one_char(hex_chars[n]));
    print_hex(n / 16, hex_chars);
    return (1 + print_one_char(hex_chars[n % 16]));
}