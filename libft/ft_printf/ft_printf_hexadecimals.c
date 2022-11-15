/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexadecimals.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:01:58 by gusouza-          #+#    #+#             */
/*   Updated: 2022/07/24 11:08:08 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_lower(unsigned long int hex)
{
	int	hex_len;

	hex_len = 0;
	if (hex >= 16)
	{
		hex_len += hex_lower((hex / 16));
		hex_len += hex_lower((hex % 16));
	}
	else if (hex >= 10 && hex <= 15)
	{
		ft_putchar_fd((hex + 87), 1);
		return (hex_len + 1);
	}
	else
	{
		ft_putchar_fd((hex + '0'), 1);
		return (hex_len + 1);
	}
	return (hex_len);
}

static int	hex_upper(unsigned long int hex)
{
	int	hex_len;

	hex_len = 0;
	if (hex >= 16)
	{
		hex_len += hex_upper((hex / 16));
		hex_len += hex_upper((hex % 16));
	}
	else if (hex >= 10 && hex <= 15)
	{
		ft_putchar_fd((hex + 55), 1);
		return (hex_len + 1);
	}
	else
	{
		ft_putchar_fd((hex + '0'), 1);
		return (hex_len + 1);
	}
	return (hex_len);
}

int	write_hex(long int hex, char c)
{
	int	hex_len;

	hex_len = 0;
	if (c == 'x')
	{
		if (hex < INT_MIN || hex > UNSIGNED_INT)
			hex_len += hex_lower((unsigned long int)hex);
		else if (hex >= INT_MIN && hex < 0)
			hex_len += hex_lower((unsigned int)hex);
		else
			hex_len += hex_lower(hex);
		return (hex_len);
	}
	if (hex < INT_MIN || hex > UNSIGNED_INT)
		hex_len += hex_upper((unsigned long int)hex);
	else if (hex >= INT_MIN && hex < 0)
		hex_len += hex_upper((unsigned int)hex);
	else
		hex_len += hex_upper(hex);
	return (hex_len);
}
