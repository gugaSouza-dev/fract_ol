/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:03:41 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:03:42 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_holder;
	unsigned char	c_holder;
	size_t			i;

	i = 0;
	s_holder = (unsigned char *)s;
	c_holder = (unsigned char)c;
	while (i < n)
	{
		if (*s_holder == c_holder)
			return ((void *)s_holder);
		s_holder++;
		i++;
	}
	return (NULL);
}
