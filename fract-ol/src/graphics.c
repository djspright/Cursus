/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:29:22 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 11:32:35 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_mlx(t_fractal *fractal, t_image *image)
{
	fractal->complex = 0; // Initialize complex number
	fractal->threshold = 100; // Set a default threshold for iterations
	image->data = malloc(WIDTH * HEIGHT * sizeof(int)); // Allocate memory for image data
	if (!image->data)
	{
		write(2, "Memory allocation failed\n", 25);
		exit(EXIT_FAILURE);
	}
}

void create_image(t_fractal *fractal, t_image *image)
{
	int x, y;
}

void put_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return; // Out of bounds check
	((int *)image->data)[y * WIDTH + x] = color; // Assuming image data is a 1D array
}

void render_fractal(t_fractal *fractal, t_image *image)
{
	int x, y;
	int color;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			color = mandelbrot_pixel(fractal, image, x, y); // Calculate pixel color
			put_pixel(image, x, y, color); // Put pixel in image
		}
	}
}

void display_image(t_image *image);
