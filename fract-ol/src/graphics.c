/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:29:22 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/20 17:18:11 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		error_exit("Failed to initialize MLX\n", fractal);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractal");
	if (!fractal->win)
		error_exit("Failed to create window\n", fractal);
}

void	create_image(t_fractal *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		error_exit("Failed to create image\n", fractal);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bpp,
			&fractal->line_length, &fractal->endian);
	if (!fractal->addr)
		error_exit("Failed to get image data address\n", fractal);
}

void	put_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bpp / 8));
	*(unsigned int *)dst = color;
}

void	render_fractal(t_fractal *fractal)
{
	if (fractal->fractal_type == MANDELBROT)
		mandelbrot_set(fractal);
	else if (fractal->fractal_type == JULIA)
		julia_set(fractal);
	display_image(fractal);
}

void	display_image(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
