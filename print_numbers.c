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

int get_num_len(unsigned int n);

int print_unsigned_int(unsigned int n)
{
    int n_len;
    char digit;

    n_len = get_num_len(n);
	if (n >= 10)
	{
		print_unsigned_int(n / 10);
		print_unsigned_int(n % 10);
	}
	else
    {
        digit = n + '0';
	    write(1, &digit, 1);
    }
    return (n_len);
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

int get_num_len(unsigned int n)
{
    if (n > 10)
        return (1 + get_num_len(n / 10));
    return (1);
}