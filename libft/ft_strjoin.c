/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:04:53 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:04:54 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_join(char const *s1, char const *s2, char *new_string)
{
	int		i;
	int		i_s2;

	i = 0;
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	i_s2 = i;
	i = 0;
	while (s2[i] != '\0')
	{
		new_string[i_s2 + i] = s2[i];
		i++;
	}
	return (i_s2 + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		full_len;
	size_t	s1s2_size;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	s1s2_size = (ft_strlen(s1)) + (ft_strlen(s2)) + 1;
	new_string = malloc(s1s2_size * sizeof(char));
	if (!new_string)
		return (NULL);
	full_len = ft_join(s1, s2, new_string);
	new_string[full_len] = '\0';
	return (new_string);
}
