/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 09:40:33 by sngantch          #+#    #+#             */
/*   Updated: 2025/03/05 00:06:04 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	strlen_split(char const *s, char c)
{
	const char	*p;

	p = s;
	while (*p != '\0' && (*p != c))
		p++;
	return (p - s);
}

char	*putstr(char const *s, char c)
{
	char	*str;
	size_t	str_len;
	size_t	i;

	str_len = strlen_split(s, c);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s != '\0' && (*s != c))
			count++;
		while (*s && (*s != c))
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		count;
	size_t	i;

	count = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s != '\0' && (*s != c))
		{
			tab[i] = putstr(s, c);
			i++;
		}
		while (*s && (*s != c))
			s++;
	}
	tab[i] = 0;
	return (tab);
}
