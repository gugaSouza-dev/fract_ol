/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:45:42 by gusouza-          #+#    #+#             */
/*   Updated: 2022/11/12 19:34:58 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	char	*byte;

	byte = f->win.addr + ((y * f->win.linel) + (x * f->win.img_bpp / 8));
	*(unsigned int *)byte = color;
}

static void	init_img(t_fractol *f)
{
	f->win.img = mlx_new_image(f->win.mlx, W_W, W_H);
	f->win.addr = mlx_get_data_addr(f->win.img, &f->win.img_bpp,
			&f->win.linel, &f->win.endian);
}

void	render_mand(t_fractol *f)
{
	int		x;
	int		y;
	double	cartesian_r;
	double	cartesian_i;
	int		iter;

	init_img(f);
	y = -1;
	while (y++ < W_H)
	{
		x = -1;
		while (x++ < W_W)
		{
			cartesian_r = f->min_r + (double)x * (f->max_r - f->min_r) / W_W;
			cartesian_i = f->min_i + (double)y * (f->max_i - f->min_i) / W_H;
			iter = calculate_mandelbrot(cartesian_r, cartesian_i);
			if (iter > MAX_ITERATIONS)
				set_pixel_color(f, x, y, BLACK);
			else
				set_pixel_color(f, x, y, (iter * COLOR));
		}
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
	mlx_destroy_image(f->win.mlx, f->win.img);
}

void	render_jul(t_fractol *f)
{
	int		x;
	int		y;
	double	cartesian_r;
	double	cartesian_i;
	int		iter;

	init_img(f);
	y = -1;
	while (y++ < W_H)
	{
		x = -1;
		while (x++ < W_W)
		{
			cartesian_r = f->min_r + (double)x * (f->max_r - f->min_r) / W_W;
			cartesian_i = f->min_i + (double)y * (f->max_i - f->min_i) / W_H;
			iter = calculate_julia(f, cartesian_r, cartesian_i);
			if (iter > MAX_ITERATIONS)
				set_pixel_color(f, x, y, BLACK);
			else
				set_pixel_color(f, x, y, (iter * 0x0A0103));
		}
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->win.img, 0, 0);
	mlx_destroy_image(f->win.mlx, f->win.img);
}
