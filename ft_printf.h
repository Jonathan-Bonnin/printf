/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathan <jonathan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:05:22 by jonathan          #+#    #+#             */
/*   Updated: 2023/04/09 17:55:33 by jonathan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int decide_what_to_print(const char *format, va_list args);
int print_one_char(char c);
int print_str(char *c);
int print_unsigned_int(unsigned int n);
int print_signed_int(int n);
int print_hex(long unsigned int n, const char *hex_chars);

#endif