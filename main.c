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
	ft_printf("%d, %s", 42, "Hehehe salut");
	printf("\n");
	printf("%d, %s", 42, "Hehehe salut");
	return (0);
}