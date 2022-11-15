/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:01:55 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/06 15:03:42 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_memory;
	void	*pointer;

	total_memory = nmemb * size;
	if (nmemb != 0 && total_memory / nmemb != size)
		return (NULL);
	pointer = malloc(total_memory);
	if (!pointer)
		return (NULL);
	ft_memset(pointer, 0, total_memory);
	return (pointer);
}
