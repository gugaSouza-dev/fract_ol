/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 01:20:04 by gusouza-          #+#    #+#             */
/*   Updated: 2022/11/15 22:12:47 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	end_fractol(t_fractol *f)
{
	mlx_destroy_window(f->win.mlx, f->win.win);
	mlx_destroy_display(f->win.mlx);
	free (f->win.mlx);
	free (f);
	exit (0);
}

static void	reset(t_fractol *f)
{
	if (f->set == 'm')
	{
		f->min_r = -2.0;
		f->max_r = 0.75;
		f->min_i = -1.5;
		f->max_i = 1.5;
		render_mand(f);
	}
	if (f->set == 'j')
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
		render_jul(f);
	}
}

int	key_event(int key_value, t_fractol *f)
{
	if (key_value == RESET)
		reset(f);
	if (key_value == KEY_ESC)
	{
		mlx_destroy_window(f->win.mlx, f->win.win);
		mlx_destroy_display(f->win.mlx);
		free (f->win.mlx);
		free (f);
		exit (0);
	}
	return (0);
}

int	zoom(int keycode, int x, int y, t_fractol *f)
{
	double	dx;
	double	dy;

	dx = (f->max_r - f->min_r) / W_W;
	dy = (f->max_i - f->min_i) / W_H;
	if (keycode == ZOOM_IN)
	{
		f->min_r += (x * dx) * 0.65;
		f->max_r -= ((W_W - x) * dx) * 0.65;
		f->min_i += (y * dy) * 0.65;
		f->max_i -= ((W_H - y) * dy) * 0.65;
	}
	if (keycode == ZOOM_OUT)
	{
		f->min_r -= ((W_W - x) * dx) * 0.65;
		f->max_r += (x * dx) * 0.65;
		f->min_i -= ((W_H - y) * dy) * 0.65;
		f->max_i += (y * dy) * 0.65;
	}
	if (f->set == 'm')
		render_mand(f);
	if (f->set == 'j')
		render_jul(f);
	return (0);
}
