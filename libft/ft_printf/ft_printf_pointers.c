/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:23:04 by gusouza-          #+#    #+#             */
/*   Updated: 2022/07/14 18:46:09 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_ptr(unsigned long int nbr)
{
	int					ptr_len;
	unsigned long int	base;

	ptr_len = 0;
	base = 16;
	if (nbr >= base)
	{
		ptr_len += write_ptr(nbr / base);
		ptr_len += write_ptr(nbr % base);
	}
	else if (nbr >= 10 && nbr <= 15)
	{
		ft_putchar_fd((nbr + 87), 1);
		return (ptr_len + 1);
	}
	else
	{
		ft_putchar_fd((nbr + '0'), 1);
		return (ptr_len + 1);
	}
	return (ptr_len);
}

int	pointer_check_s(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}

int	pointer_check_p(long int ptr)
{
	int	ptr_len;

	ptr_len = 0;
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ptr_len += 2;
	ptr_len += write_ptr(ptr);
	return (ptr_len);
}
