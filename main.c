/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:40:06 by jbonnin           #+#    #+#             */
/*   Updated: 2023/03/19 16:19:27 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main (void)
{
	char *str = "Hehe salut";
	int data = 0;
	int data1 = 29;
	int data2 = 4095;
	int data3 = 4096;
	int data4 = 13465;
	int data5 = -72;
	   printf("Hex OG: %x, %x, %X, %x, %x, %x \n", data, data1, data2, data3, data4, data5);
	ft_printf("Hex ft: %x, %x, %X, %x, %x, %x \n", data, data1, data2, data3, data4, data5);
	   printf("%d, %s, %c, %i, %u, %%\n", -42, str, 'n', -2147483647, 429496729);
	ft_printf("%d, %s, %c, %i, %u, %%\n", -42, str, 'n', -2147483647, 429496729);
	   printf("OG str adr:%p\n", &str);
	ft_printf("FT str adr:%p\n", &str);
	return (0);
}