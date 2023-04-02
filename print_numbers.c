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

int print_unsigned_int(unsigned int n)
{
    int n_len;

    n_len = 0;
    while (n) //what if we need to print 0
    {
        n_len++;
        if (n < 10)
            write(1, n, 1);
        else
        {
            print_unsigned_int(n / 10);
            print_unsigned_int(n % 10);
        }
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