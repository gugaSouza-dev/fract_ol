/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:05:20 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/04 18:05:21 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_caster;
	unsigned char	*s2_caster;

	i = 0;
	s1_caster = (unsigned char *)s1;
	s2_caster = (unsigned char *)s2;
	while (i < n && (s1_caster[i] || s2_caster[i]))
	{
		if (s1_caster[i] != s2_caster[i])
			return (s1_caster[i] - s2_caster[i]);
		i++;
	}
	return (0);
}
