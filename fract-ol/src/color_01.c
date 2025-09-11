/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:41:44 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/11 23:57:56 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_basic(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(t * 255);
	g = (int)(t * 127);
	b = (int)(t * 63);
	return (r << 16 | g << 8 | b);
}

int	get_color_ocean(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(t * 64);
	g = (int)(t * 128);
	b = (int)(t * 255);
	return (r << 16 | g << 8 | b);
}

int	get_color_fire(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	r = (int)(t * 255);
	g = 0;
	b = 0;
	if (t > 0.5)
		g = (int)((t - 0.5) * 2 * 255);
	return (r << 16 | g << 8 | b);
}

int	get_color_rainbow(int iter, int max_iter)
{
	double	t;
	double	cycle;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / max_iter;
	cycle = t * 6.0;
	r = (int)(127 * (1 + sin(cycle)));
	g = (int)(127 * (1 + sin(cycle + 2.0)));
	b = (int)(127 * (1 + sin(cycle + 4.0)));
	return (r << 16 | g << 8 | b);
}
