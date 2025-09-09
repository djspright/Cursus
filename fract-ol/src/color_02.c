/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:30 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/23 23:25:54 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_scheme(int iter, int max_iter, int scheme)
{
	if (scheme == 1)
		return (get_color_basic(iter, max_iter));
	else if (scheme == 2)
		return (get_color_ocean(iter, max_iter));
	else if (scheme == 3)
		return (get_color_fire(iter, max_iter));
	else if (scheme == 4)
		return (get_color_rainbow(iter, max_iter));
	return (get_color_basic(iter, max_iter));
}

int	get_shifted_color(int iter, int max_iter, int scheme, int shift)
{
	int	base_color;

	base_color = get_color_scheme(iter, max_iter, scheme);
	if (shift != 0)
		base_color = apply_color_shift(base_color, shift);
	return (base_color);
}

static int	calculate_rgb_value(int start, int end, double t)
{
	return ((int)((1 - t) * start + t * end));
}

int	color_interpolate(int start_color, int end_color, double t)
{
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_rgb[3];
	int	result;

	start_r = (start_color >> 16) & 0xFF;
	start_g = (start_color >> 8) & 0xFF;
	start_b = start_color & 0xFF;
	end_rgb[0] = (end_color >> 16) & 0xFF;
	end_rgb[1] = (end_color >> 8) & 0xFF;
	end_rgb[2] = end_color & 0xFF;
	result = (calculate_rgb_value(start_r, end_rgb[0], t) << 16)
		| (calculate_rgb_value(start_g, end_rgb[1], t) << 8)
		| calculate_rgb_value(start_b, end_rgb[2], t);
	return (result);
}
