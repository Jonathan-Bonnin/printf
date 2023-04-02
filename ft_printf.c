/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:33:55 by jbonnin           #+#    #+#             */
/*   Updated: 2023/03/19 14:37:21 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	int total_chars_printed;
	// handle cspdiuxX%
	// comparison vs printf
	// return nb of chars printed
	total_chars_printed = 0;
	while (*format) 
	{
		write(1, format, 1);
		format++;
		total_chars_printed++;
	}
	return (total_chars_printed);
}

