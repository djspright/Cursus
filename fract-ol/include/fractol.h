/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:35:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/11 21:46:54 by shkondo          ###   ########.fr       */
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
# define BURNING_SHIP 3
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define KEY_ESCAPE 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_C 99
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

t_complex		mandelbrot_pixel_to_complex(int x, int y, t_fractal *fractal);
int				mandelbrot_iterate(t_complex c, int max_iter);
int				mandelbrot_color(int iter, int max_iter, t_fractal *fractal);
void			mandelbrot_set(t_fractal *fractal);

t_complex		julia_pixel_to_complex(int x, int y, t_fractal *fractal);
int				julia_iterate(t_complex z, t_complex c, int max_iter);
int				julia_color(int iter, int max_iter, t_fractal *fractal);
void			julia_set(t_fractal *fractal);

t_complex		burning_ship_pixel_to_complex(int x, int y, t_fractal *fractal);
t_complex		complex_abs_mul(t_complex z);
int				burning_ship_iterate(t_complex c, int max_iter);
void			burning_ship_set(t_fractal *fractal);

void			setup_hooks(t_fractal *fractal);
int				handle_keypress(int keycode, t_fractal *fractal);
int				handle_mouse(int button, int x, int y, t_fractal *fractal);
int				handle_zoom(int direction, int x, int y, t_fractal *fractal);
int				handle_close(t_fractal *fractal);

int				handle_arrow_keys(int keycode, t_fractal *fractal);
int				handle_color_keys(int keycode, t_fractal *fractal);

int				get_color_basic(int iter, int max_iter);
int				get_color_ocean(int iter, int max_iter);
int				get_color_fire(int iter, int max_iter);
int				get_color_rainbow(int iter, int max_iter);
int				apply_color_shift(int color, int shift);

int				get_color_scheme(int iter, int max_iter, int scheme);
int				get_shifted_color(int iter, int max_iter, int scheme,
					int shift);
int				color_interpolate(int start_color, int end_color, double t);

double			ft_atof(char *str);
void			cleanup_exit(t_fractal *fractal);
void			error_exit(const char *message, t_fractal *fractal);

void			init_fractal(t_fractal *fractal);

#endif
