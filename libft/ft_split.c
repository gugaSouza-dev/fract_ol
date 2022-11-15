/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:04:35 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/18 01:54:50 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_count(char const *s, char c)
{
	int	splits;
	int	i;

	splits = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			splits++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (splits);
}

static char	**splitter(char **new_array, char const *s, char c)
{
	int		i;
	int		str_len;

	i = 0;
	while (*s)
	{
		str_len = 0;
		while (s[str_len] != c && s[str_len])
			str_len++;
		new_array[i] = malloc((str_len + 1) * sizeof(char));
		if (!new_array)
			return (NULL);
		new_array[i][str_len] = '\0';
		while (str_len > 0)
		{
			new_array[i][str_len - 1] = s[str_len - 1];
			str_len--;
		}
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	return (new_array);
}

char	**ft_split(char const *s, char c)
{
	int		split;
	char	**new_array;

	if (!s)
		return (NULL);
	split = split_count(s, c);
	new_array = malloc((split + 1) * sizeof(char *));
	if (!new_array)
		return (NULL);
	while (*s == c && *s)
		s++;
	new_array = splitter(new_array, s, c);
	new_array[split] = NULL;
	return (new_array);
}
