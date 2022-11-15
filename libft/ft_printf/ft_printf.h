/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:09:54 by gusouza-          #+#    #+#             */
/*   Updated: 2022/07/24 11:58:47 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

# define UNSIGNED_INT 4294967295
# define INT_MIN -2147483648
# define INT_MAX 2147483647

int		ft_printf(const char *str, ...);
int		pointer_check_s(char *str);
int		pointer_check_p(long int ptr);
int		putnbr(int n);
int		unsigned_check(int nbr);
int		write_hex(long int hex, char c);

#endif