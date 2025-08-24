/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:04:57 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/24 15:04:58 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	julia_pixel_to_complex(int x, int y, t_fractal *fractal)
{
	t_complex	z;

	z.real = (x - fractal->width / 2.0) * fractal->zoom + fractal->offset_x;
	z.imag = (y - fractal->height / 2.0) * fractal->zoom + fractal->offset_y;
	return (z);
}

int	julia_iterate(t_complex z, t_complex julia_c, int max_iter)
{
	int	iter;

	iter = 0;
	while (iter < max_iter)
	{
		z = complex_add(complex_mul(z, z), julia_c);
		if (complex_magnitude(z) > 2.0)
			break ;
		iter++;
	}
	return (iter);
}

int	julia_color(int iter, int max_iter, t_fractal *fractal)
{
	int	base_color;

	if (iter == max_iter)
		return (0x000000);
	base_color = get_color_scheme(iter, max_iter, fractal->color_scheme);
	if (fractal->color_shift != 0)
		base_color = apply_color_shift(base_color, fractal->color_shift);
	return (base_color);
}

void	julia_set(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	z;
	int			iter;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = julia_pixel_to_complex(x, y, fractal);
			iter = julia_iterate(z, fractal->julia_c, fractal->max_iter);
			color = julia_color(iter, fractal->max_iter, fractal);
			put_pixel(fractal, x, y, color);
			x++;
		}
		y++;
	}
}
