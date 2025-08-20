/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:45:38 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/20 17:09:19 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	mandelbrot_pixel_to_complex(int x, int y, t_fractal *fractal)
{
	t_complex	c;

	c.real = (x - fractal->width / 2.0) * fractal->zoom + fractal->offset_x;
	c.imag = (y - fractal->height / 2.0) * fractal->zoom + fractal->offset_y;
	return (c);
}

int	mandelbrot_iterate(t_complex c, int max_iter)
{
	t_complex	z;
	int			iter;

	z.real = 0.0;
	z.imag = 0.0;
	iter = 0;
	while (iter < max_iter)
	{
		z = complex_add(complex_mul(z, z), c);
		if (complex_magnitude(z) > 2.0)
			break ;
		iter++;
	}
	return (iter);
}

int	mandelbrot_color(int iter, int max_iter, t_fractal *fractal)
{
	int	base_color;

	if (iter == max_iter)
		return (0x000000);
	base_color = get_color_scheme(iter, max_iter, fractal->color_scheme);
	if (fractal->color_shift != 0)
		base_color = apply_color_shift(base_color, fractal->color_shift);
	return (base_color);
}

void	mandelbrot_set(t_fractal *fractal)
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
			c = mandelbrot_pixel_to_complex(x, y, fractal);
			iter = mandelbrot_iterate(c, fractal->max_iter);
			color = mandelbrot_color(iter, fractal->max_iter, fractal);
			put_pixel(fractal, x, y, color);
			x++;
		}
		y++;
	}
}
