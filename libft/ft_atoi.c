/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:01:28 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/10 20:15:22 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_checkspc(const char *nptr)
{
	while ((9 <= *nptr && *nptr <= 15) || *nptr == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	return_value;
	int	negative;

	return_value = 0;
	negative = 1;
	while (atoi_checkspc(nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negative *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		return_value *= 10;
		return_value += (*nptr - '0');
		nptr++;
	}
	return (return_value * negative);
}
