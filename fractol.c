/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:37:00 by gusouza-          #+#    #+#             */
/*   Updated: 2022/11/12 03:42:43 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_check(char *s)
{
	if (!s)
		return (0);
	if (ft_strncmp(s, "Mandelbrot", 10) == 0)
		return (1);
	if (ft_strncmp(s, "Julia", 5) == 0)
		return (2);
	return (0);
}

void	show_options(void)
{
	ft_printf("============================================================\n");
	ft_printf(" _______ _______ _______ ________________ _______ _       \n");
	ft_printf("(  ____ (  ____ |  ___  |  ____ \\__   __/(  ___  | \\      \n");
	ft_printf("| (    \\/ (    )| (   ) | (    \\/  ) (   | (   ) | (      \n");
	ft_printf("| (__   | (____)| (___) | |        | |   | |   | | |      \n");
	ft_printf("|  __)  |     __)  ___  | |        | |   | |   | | |      \n");
	ft_printf("| (     | (\\ (  | (   ) | |        | |   | |   | | |      \n");
	ft_printf("| )     | ) \\ \\_| )   ( | (____/\\  | |   | (___) | (____/\n");
	ft_printf("|/      |/   \\__//     \\(_______/  )_(___(_______|_______/\n");
	ft_printf("\nWELCOME TO FRACT_OL\n\nAvailable Options:\n\tMandelbrot\n");
	ft_printf("\tJulia\n\nPress \"R\" to reset the image\nOBS:\nTo see Julia");
	ft_printf(" set, you'll need to pass two number values between 2 and -2\n");
	ft_printf("Example: ./fractol Julia 1.123 4.567\n");
	ft_printf("============================================================\n");
}

int	main(int argc, char **argv)
{
	int	set;

	set = set_check(argv[1]);
	if (set == 0 || argc < 2)
		show_options();
	else if (set == 1 && argc == 2)
		mandelbrot();
	else if (set == 2 && argc == 4
		&& julia_check(argv[2]) && julia_check(argv[3]))
		julia(ft_atof(argv[2]), ft_atof(argv[3]));
	else
		show_options();
	return (0);
}
