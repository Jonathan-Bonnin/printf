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

    n_len = get_num_len(n);
	if (n >= 10)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putnbr_fd(m % 10, fd);
	}
	else
		ft_putchar_fd(m + '0', fd);
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