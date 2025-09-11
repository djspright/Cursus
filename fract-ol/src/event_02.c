/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:35:01 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/11 22:48:54 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_arrow_keys(int keycode, t_fractal *fractal)
{
	double	move_step;

	move_step = 0.1 * fractal->zoom;
	if (keycode == KEY_LEFT)
		fractal->offset_x += move_step;
	else if (keycode == KEY_RIGHT)
		fractal->offset_x -= move_step;
	else if (keycode == KEY_UP)
		fractal->offset_y += move_step;
	else if (keycode == KEY_DOWN)
		fractal->offset_y -= move_step;
	else
		return (0);
	render_fractal(fractal);
	return (1);
}

int	handle_color_keys(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_C)
	{
		fractal->color_scheme = (fractal->color_scheme % 4) + 1;
		render_fractal(fractal);
		return (1);
	}
	else if (keycode == KEY_S)
	{
		fractal->color_shift += 20;
		if (fractal->color_shift > 255)
			fractal->color_shift = 0;
		render_fractal(fractal);
		return (1);
	}
	return (0);
}
