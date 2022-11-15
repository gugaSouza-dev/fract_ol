/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:54:06 by gusouza-          #+#    #+#             */
/*   Updated: 2022/07/24 11:22:44 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	check_suff(va_list args, const char *str, int i)
{
	int	printed;

	printed = 0;
	i++;
	if (str[i] == '%')
		ft_putchar_fd('%', 1);
	else if (str[i] == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (str[i] == 's')
		printed = pointer_check_s(va_arg(args, char *));
	else if (str[i] == 'p')
		printed = pointer_check_p(va_arg(args, long int));
	else if (str[i] == 'i' || str[i] == 'd')
		printed = putnbr(va_arg(args, int));
	else if (str[i] == 'u')
		printed = unsigned_check(va_arg(args, int));
	else if (str[i] == 'x' || str[i] == 'X')
		printed = write_hex(va_arg(args, int), str[i]);
	else
		return (-1);
	if (str[i] == '%' || str[i] == 'c')
		return (1);
	return (printed);
}

static int	print_handler(va_list args, const char *str, int i, int *i_ptr)
{
	int	raw_printed_value;

	raw_printed_value = 0;
	if (str[i] != '%')
	{
		ft_putchar_fd(str[i], 1);
		*i_ptr += 1;
		return (1);
	}
	raw_printed_value = check_suff(args, str, i);
	if (raw_printed_value < 0)
		return (-1);
	*i_ptr += 2;
	return (raw_printed_value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		*i_ptr;
	int		printed;
	int		raw_printed;

	i = 0;
	i_ptr = &i;
	printed = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		raw_printed = print_handler(args, str, i, i_ptr);
		if (raw_printed < 0)
			return (-1);
		printed += raw_printed;
	}
	va_end(args);
	return (printed);
}
