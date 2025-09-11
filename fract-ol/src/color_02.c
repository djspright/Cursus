/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:30 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/12 00:01:18 by shkondo          ###   ########.fr       */
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

int	apply_color_shift(int color, int shift)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (r + shift) % 256;
	g = (g + shift) % 256;
	b = (b + shift) % 256;
	return (r << 16 | g << 8 | b);
}
