/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:15:10 by jbonnin           #+#    #+#             */
/*   Updated: 2023/04/02 15:19:14 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

print_one_char(char c)
{
    write(1, c, 1);
    return (1);
}

print_percent_sign()
{
    return print_one_char('%');
}

print_string(char *c)
{
    int i;

    i = 0;
    while (c[i])
    {
        write(1, c[i], 1);
        i++;
    }
    return(i);
}