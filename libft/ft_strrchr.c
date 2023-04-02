/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:50:06 by jbonnin           #+#    #+#             */
/*   Updated: 2023/01/17 20:36:40 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*copy;

	i = 0;
	while (s[i])
		i++;
	copy = (char *) s;
	if (c == 0)
		return (&copy[i]);
	while (--i >= 0)
		if (s[i] == c)
			return (&copy[i]);
	return (0);
}
