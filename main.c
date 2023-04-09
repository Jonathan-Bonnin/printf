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

int main (void)
{
	char *str = "Hehe salut";
	int data = 0;
	int data1 = 29;
	int data2 = 4095;
	int data3 = 4096;
	int data4 = 13465;
	printf("Hex OG: %x, %x, %X, %x, %x \n", data, data1, data2, data3, data4);
	ft_printf("Hex ft: %x, %x, %X, %x, %x \n", data, data1, data2, data3, data4);
	ft_printf("%d, %s, %c, %i, %u, %%\n", -42, str, 'n', -2147483647, 429496729);
	printf("%d, %s, %c, %i, %u, %p, %%\n", -42, str, 'n', -2147483647, 429496729, &str);
	return (0);
}