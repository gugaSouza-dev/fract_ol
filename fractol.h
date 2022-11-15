/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:34:03 by gusouza-          #+#    #+#             */
/*   Updated: 2022/11/15 22:11:39 by gusouza-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include "./libft/libft.h"

# define MAX_ITERATIONS 600

//window height and width
# define W_H 600
# define W_W 600

//colors
# define COLOR 0x0A0103
# define BLACK 0x000000

//events key values
# define CLOSE_WIN 17
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define KEY_ESC 65307
# define RESET 114

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		img_bpp;
	int		linel;
	int		endian;
}	t_window;

typedef struct s_fractol
{
	t_window	win;
	double		min_r;
	double		max_r;
	double		max_i;
	double		min_i;
	float		jr;
	float		ji;
	char		set;
}	t_fractol;

//Mandelbrot
int		calculate_mandelbrot(double pr, double pi);
void	mandelbrot(void);
void	render_mand(t_fractol *f);

//Julia
int		calculate_julia(t_fractol *f, float zr, float zi);
int		julia_check(char *s);
void	julia(float r, float i);
void	render_jul(t_fractol *f);
float	ft_atof(char *s);

int		calculate_fractal(double pr, double pi);
int		end_fractol(t_fractol *f);
int		key_event(int key_value, t_fractol *f);
int		zoom(int keycode, int x, int y, t_fractol *f);
void	init(t_fractol *f);
void	show_options(void);

#endif