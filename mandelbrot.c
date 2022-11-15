/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:32:49 by gusouza-          #+#    #+#             */
/*   Updated: 2022/11/12 19:43:46 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(double cart_r, double cart_i)
{
	int		interations;
	double	zr;
	double	zi;
	double	tmp;

	interations = 0;
	zr = 0;
	zi = 0;
	while (interations < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + cart_i;
		zr = zr * zr - zi * zi + cart_r;
		zi = tmp;
		interations++;
	}
	if (interations == MAX_ITERATIONS)
		return (interations + 1);
	return (interations);
}

void	mandelbrot(void)
{
	t_fractol	*f;

	f = (t_fractol *) malloc(sizeof(t_fractol));
	f->win.mlx = mlx_init();
	f->win.win = mlx_new_window(f->win.mlx, W_W, W_H, "Fract-ol Mandelbrot");
	f->min_r = -2.0;
	f->max_r = 0.75;
	f->min_i = -1.5;
	f->max_i = 1.5;
	f->set = 'm';
	render_mand(f);
	mlx_hook(f->win.win, CLOSE_WIN, 0, end_fractol, f);
	mlx_mouse_hook(f->win.win, zoom, f);
	mlx_key_hook(f->win.win, key_event, f);
	mlx_expose_hook(f->win.win, (void *)render_mand, f);
	mlx_loop(f->win.mlx);
}
