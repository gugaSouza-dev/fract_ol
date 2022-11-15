/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:04:00 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:04:01 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	replace_char;
	char	*s_char;

	i = 0;
	replace_char = (char)c;
	s_char = (char *)s;
	while (i < n)
	{
		s_char[i] = replace_char;
		i++;
	}
	return ((void *)s);
}
