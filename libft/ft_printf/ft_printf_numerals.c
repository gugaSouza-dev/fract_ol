/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numerals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:00:56 by gusouza-          #+#    #+#             */
/*   Updated: 2022/07/15 10:40:03 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_unsigned(unsigned int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr >= 10)
	{
		nbr_len += write_unsigned(nbr / 10);
		nbr_len += write_unsigned(nbr % 10);
	}
	else
	{
		ft_putchar_fd((nbr + '0'), 1);
		nbr_len += 1;
	}
	return (nbr_len);
}

int	unsigned_check(int nbr)
{
	unsigned int	un_nbr;

	un_nbr = (unsigned int)nbr;
	if (nbr < 0)
		return (write_unsigned(un_nbr));
	return (write_unsigned(nbr));
}

static int	max_numbers(int nbr)
{
	if (nbr == INT_MAX)
	{
		ft_putstr_fd("2147483647", 1);
		return (10);
	}
	ft_putstr_fd("-2147483648", 1);
	return (11);
}

int	putnbr(int nbr)
{
	int	nlen;

	nlen = 0;
	if (nbr == INT_MAX || nbr == INT_MIN)
		return (max_numbers(nbr));
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		nlen += 1;
		nbr = nbr * -1;
		nlen += putnbr(nbr);
	}
	else if (nbr > 9)
	{
		nlen += putnbr(nbr / 10);
		nlen += putnbr(nbr % 10);
	}
	else
	{
		ft_putchar_fd(nbr + '0', 1);
		return (nlen + 1);
	}
	return (nlen);
}
