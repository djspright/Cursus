/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:45:38 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 11:54:10 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_set(int center, int magnification, int threshold)
{
	int	z;

	z = 0;
	for (int i = 0; i < t_fractal->threshold; i++)
	{
		z = add(pow(z, 2), t_fractal->complex);
		if (abs(z) > t_fractal->threshold)
		{
			return (1);
			break ;
		}
	}
	return (0);
}

void	mandelbrot_calc(t_fractal *fractal, t_image *image)
{
	int	z;

	int x, y;
	z = 0;
	for (int i = 0; i < fractal->threshold; i++)
	{
		z = add(pow(z, 2), fractal->complex);
		if (abs(z) > fractal->threshold)
		{
			return (0); // Assuming image data is a 1D array
			break ;
		}
	}
	return (1);
}

void	mandelbrot_pixel(t_fractal *fractal, t_image *image, int x, int y)
{
	int	color;

	color = 0;
	image->data[y * WIDTH + x] = color;
}

void	mandelbrot_color(t_fractal *fractal, t_image *image, int x, int y)
{
	int	color;

	color = 0;
	image->data[y * WIDTH + x] = color;
}
