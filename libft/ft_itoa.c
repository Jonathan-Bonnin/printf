/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:24:16 by jbonnin           #+#    #+#             */
/*   Updated: 2023/01/21 21:54:53 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int n);
static char	get_char(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		int_len;

	int_len = get_int_len(n);
	str = malloc(int_len + 1);
	if (!str)
		return (NULL);
	str[int_len] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[int_len - 1] = get_char(n);
		n /= 10;
		int_len--;
	}
	return (str);
}

static char	get_char(int n)
{
	if (n >= 0)
		return (n % 10 + '0');
	return (-(n % 10) + '0');
}

static int	get_int_len(int n)
{
	int	len;

	if (n > 0)
		len = 0;
	else
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}
