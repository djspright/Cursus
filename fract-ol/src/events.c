/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:39:40 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/20 17:12:55 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win, 2, 1L << 0, handle_keypress, fractal);
	mlx_hook(fractal->win, 4, 1L << 2, handle_mouse, fractal);
	mlx_hook(fractal->win, 17, 0L, handle_close, fractal);
	mlx_loop(fractal->mlx);
}

int	handle_keypress(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESCAPE)
		cleanup_exit(fractal);
	else if (keycode == 99)
	{
		fractal->color_scheme = (fractal->color_scheme % 4) + 1;
		render_fractal(fractal);
	}
	else if (keycode == 115)
	{
		fractal->color_shift += 20;
		if (fractal->color_shift > 255)
			fractal->color_shift = 0;
		render_fractal(fractal);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == MOUSE_SCROLL_UP)
		handle_zoom(1, x, y, fractal);
	else if (button == MOUSE_SCROLL_DOWN)
		handle_zoom(-1, x, y, fractal);
	return (0);
}

int	handle_zoom(int direction, int x, int y, t_fractal *fractal)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = (x - fractal->width / 2.0) * fractal->zoom + fractal->offset_x;
	mouse_imag = (y - fractal->height / 2.0) * fractal->zoom
		+ fractal->offset_y;
	if (direction == 1)
		fractal->zoom *= 0.9;
	else
		fractal->zoom /= 0.9;
	fractal->offset_x = mouse_real - (x - fractal->width / 2.0) * fractal->zoom;
	fractal->offset_y = mouse_imag - (y - fractal->height / 2.0)
		* fractal->zoom;
	render_fractal(fractal);
	return (0);
}

int	handle_close(t_fractal *fractal)
{
	cleanup_exit(fractal);
	return (0);
}
