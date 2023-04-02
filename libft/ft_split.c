/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnin <jbonnin@42student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:14:15 by jbonnin           #+#    #+#             */
/*   Updated: 2023/02/04 17:32:07 by jbonnin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_word_count(const char *str, char separator);
static void	place_strs(char **strs, const char *str, char sep, int word_count);

char	**ft_split(const char *s, char separator)
{
	int		word_count;
	char	**split_strs;

	if (!s)
		return (NULL);
	word_count = get_word_count(s, separator);
	split_strs = malloc(sizeof(char *) * (word_count + 1));
	if (!split_strs)
		return (NULL);
	place_strs(split_strs, s, separator, word_count);
	split_strs[word_count] = NULL;
	return (split_strs);
}

static int	get_word_count(const char *s, char separator)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == separator)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != separator)
			s++;
	}
	return (word_count);
}

static void	place_strs(char **strs, const char *str, char sep, int word_count)
{
	int	i;
	int	word_start;
	int	current_count;

	i = 0;
	current_count = 0;
	while (current_count < word_count)
	{
		while (str[i] == sep)
			i++;
		word_start = i;
		while (str[i] && str[i] != sep)
			i++;
		strs[current_count] = ft_substr(str, word_start, (i - word_start));
		current_count++;
	}
}
