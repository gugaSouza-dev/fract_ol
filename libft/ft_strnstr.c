/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:05:24 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:05:25 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lil_len;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	lil_len = ft_strlen(little);
	while (big[i] != '\0' && i <= len)
	{
		if ((ft_strncmp((big + i), little, lil_len) == 0)
			&& (lil_len + i <= len))
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
