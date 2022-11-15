/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:32:02 by gusouza-          #+#    #+#             */
/*   Updated: 2022/11/12 10:48:35 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_check(char *s)
{
	int	check;

	check = 0;
	if (!s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if ((*s < '0' || *s > '9') && (*s != '.' && *s != ','))
			return (0);
		if (*s == '.' || *s == ',')
			check += 1;
		s++;
	}
	if (check > 1)
		return (0);
	return (1);
}

float	ft_atof(char *s)
{
	float	result;
	float	decimal;
	int		negative;

	negative = 1;
	decimal = 1;
	result = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			negative = -1;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + *s++ - 48;
	if ((*s == '.' || *s == ',') && *s++ != '\0')
	{
		while (*s >= '0' && *s <= '9')
		{
			decimal *= 10;
			result = result * 10 + *s++ - 48;
		}
	}
	return ((result / decimal) * negative);
}

int	calculate_julia(t_fractol *f, float zr, float zi)
{
	int		interations;
	double	tmp;

	interations = 0;
	while (interations < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ji;
		zr = zr * zr - zi * zi + f->jr;
		zi = tmp;
		interations++;
	}
	if (interations == MAX_ITERATIONS)
		return (interations + 1);
	return (interations);
}

void	julia(float r, float i)
{
	t_fractol	*f;

	if ((r >= 3 || i >= 3) || (r <= -3 || i <= -3))
	{
		show_options();
		exit (0);
	}
	f = (t_fractol *) malloc(sizeof(t_fractol));
	f->win.mlx = mlx_init();
	f->win.win = mlx_new_window(f->win.mlx, W_W, W_W, "Fract-ol Julia");
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
	f->jr = r;
	f->ji = i;
	f->set = 'j';
	render_jul(f);
	mlx_hook(f->win.win, CLOSE_WIN, 0, end_fractol, f);
	mlx_mouse_hook(f->win.win, zoom, f);
	mlx_key_hook(f->win.win, key_event, f);
	mlx_expose_hook(f->win.win, (void *)render_jul, f);
	mlx_loop(f->win.mlx);
}
