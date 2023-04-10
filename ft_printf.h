/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:05:22 by jonathan          #+#    #+#             */
/*   Updated: 2023/04/10 13:31:21 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	decide_what_to_print(const char *format, va_list args);
int	print_one_char(char c);
int	print_str(char *c);
int	print_unsigned_int(unsigned int n);
int	print_signed_int(int n);
int	print_hex(long unsigned int n, const char *hex_chars);

#endif