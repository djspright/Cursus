/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:35:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/19 10:38:56 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MANDELBROT 1
# define JULIA 2
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 1000
# define KEY_ESCAPE 65307
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;

	int			fractal_type;
	t_complex	julia_c;

	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;

	int			color_scheme;
	int			color_shift;

	int			width;
	int			height;
}				t_fractal;

t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_mul(t_complex a, t_complex b);
double			complex_magnitude(t_complex c);

void			init_mlx(t_fractal *fractal);
void			create_image(t_fractal *fractal);
void			put_pixel(t_fractal *fractal, int x, int y, int color);
void			render_fractal(t_fractal *fractal);
void			display_image(t_fractal *fractal);

t_complex		mandelbrot_pixel_to_complex(int x, int y, t_fractal *fractal);
int				mandelbrot_iterate(t_complex c, int max_iter);
int				mandelbrot_color(int iter, int max_iter);
void			mandelbrot_set(t_fractal *fractal);

void			setup_hooks(t_fractal *fractal);
int				handle_keypress(int keycode, t_fractal *fractal);
int				handle_mouse(int button, int x, int y, t_fractal *fractal);
void			handle_zoom(int direction, int x, int y, t_fractal *fractal);
int				handle_close(t_fractal *fractal);

double			ft_atof(char *str);
double			map_range(double value, double old_min, double old_max,
					double new_min, double new_max);
int				color_interpolate(int start_color, int end_color, double t);
void			cleanup_exit(t_fractal *fractal);
void			error_exit(const char *message, t_fractal *fractal);

#endif
