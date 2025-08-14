/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:39:18 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 17:11:03 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define _USE__MATH_DEFINES
# include "libft.h"
# include "minilibx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define MANDELBROT 1
# define JULIA 2
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 1000

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

int				main(int ac, char *av);
void			init_fractal(t_fractal *fractal);

t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_mul(t_complex a, t_complex b);
double			complex_magnitude(t_complex c);

#endif
