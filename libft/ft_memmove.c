/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:03:54 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/13 07:05:08 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	i = -1;
	if (!src && !dest)
		return (NULL);
	if (csrc < cdest)
	{
		while (n--)
			*(cdest + n) = *(csrc + n);
	}
	else
	{
		while (++i < n)
			*cdest++ = *csrc++;
	}
	return (dest);
}
