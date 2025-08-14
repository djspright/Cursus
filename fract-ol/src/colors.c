/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:41:44 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 11:43:50 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void create_color_palette(void)
{
    // Implementation for creating a color palette
}

void get_gradient_color(int iteration, int max_iterations)
{
	// Implementation for getting a color based on the iteration count
	// This could involve mapping the iteration count to a color in a gradient
}

void hsv_to_rgb(float h, float s, float v, int *r, int *g, int *b)
{
	float p, q, t, f;
	int i;

	if (s == 0)
	{
		*r = *g = *b = (int)(v * 255);
		return;
	}
	h /= 60;
	i = (int)h;
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - f * s);
	t = v * (1 - (1 - f) * s);

	switch (i % 6)
	{
		case 0: *r = (int)(v * 255); *g = (int)(t * 255); *b = (int)(p * 255); break;
		case 1: *r = (int)(q * 255); *g = (int)(v * 255); *b = (int)(p * 255); break;
		case 2: *r = (int)(p * 255); *g = (int)(v * 255); *b = (int)(t * 255); break;
		case 3: *r = (int)(p * 255); *g = (int)(q * 255); *b = (int)(v * 255); break;
		case 4: *r = (int)(t * 255); *g = (int)(p * 255); *b = (int)(v * 255); break;
		case 5: *r = (int)(v * 255); *g = (int)(p * 255); *b = (int)(q * 255); break;
	}
}

void shift_colors(int *r, int *g, int *b, int shift)
{
	*r = (*r + shift) % 256;
	*g = (*g + shift) % 256;
	*b = (*b + shift) % 256;
}
