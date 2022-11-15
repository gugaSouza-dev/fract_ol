/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:02:40 by gusouza-          #+#    #+#             */
/*   Updated: 2022/05/09 16:30:07 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_is_negative(int n)
{
	if (n >= 0)
		return (0);
	return (1);
}

static int	itoa_intlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n >= 1)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	is_negative;
	long int		n_holder;
	unsigned int	n_len;
	char			*str;

	is_negative = itoa_is_negative(n);
	n_holder = n;
	if (is_negative == 1)
		n_holder *= -1;
	n_len = itoa_intlen(n_holder);
	str = (char *)malloc((n_len + is_negative + 1));
	if (!str)
		return (NULL);
	if (is_negative == 1)
		str[0] = '-';
	str[n_len + is_negative] = '\0';
	while (n_len > 0)
	{
		str[(n_len - 1) + is_negative] = (n_holder % 10) + '0';
		n_holder /= 10;
		n_len--;
	}
	return (str);
}
