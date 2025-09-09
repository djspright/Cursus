/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:16:12 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/02 20:23:51 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	burning_ship_pixel_to_complex(int x, int y, t_fractal *fractal)
{
	t_complex	c;

	c.real = (x - fractal->width / 2.0) * fractal->zoom + fractal->offset_x;
	c.imag = (y - fractal->height / 2.0) * fractal->zoom + fractal->offset_y;
	return (c);
}

t_complex	complex_abs_mul(t_complex z)
{
	t_complex	result;
	double		abs_real;
	double		abs_imag;

	abs_real = fabs(z.real);
	abs_imag = fabs(z.imag);
	result.real = abs_real * abs_real - abs_imag * abs_imag;
	result.imag = 2 * abs_real * abs_imag;
	return (result);
}

int	burning_ship_iterate(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;

	z.real = 0.0;
	z.imag = 0.0;
	iter = 0;
	while (iter < max_iter)
	{
		z = complex_add(complex_abs_mul(z), c);
		if (complex_magnitude(z) > 2.0)
			break ;
		iter++;
	}
}

void	burning_ship_seg(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = burning_ship_pixel_to_complex(x, y, fractal);
			iter = burning_ship_iterate(c, fractal->max_iter);
			color = mandelbrot_color(iter, fractal->max_iter, fractal);
			put_pixel(fractal, x, y, color);
			x++;
		}
		y++;
	}
}
