/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:59:30 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/20 17:02:05 by shkondo          ###   ########.fr       */
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
