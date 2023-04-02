/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:21:42 by jbonnin           #+#    #+#             */
/*   Updated: 2023/03/11 13:37:59 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*c_s;

	c_s = (char *) s;
	i = 0;
	while (i < n)
	{
		if (c_s[i] == c)
			return (&c_s[i]);
		i++;
	}
	return (0);
}
