/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:05:34 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:05:36 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && (ft_strchr(set, *s1)))
		s1++;
	len = ft_strlen(s1);
	while (len && (ft_strchr(set, s1[len])))
		len--;
	return (ft_substr(s1, 0, len + 1));
}
