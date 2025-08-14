/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:45:53 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 11:33:41 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal julia_set()
{
	t_fractal fractal;

	fractal.type = JULIA;
	fractal.complex = 0.355 + 0.355i;
	fractal.threshold = 100;
	return (fractal);
}

void	julia_calc(t_fractal *fractal, t_image *image)
{
	int	z;

	int x, y;
	z = 0;
	for (int i = 0; i < fractal->threshold; i++)
	{
		z = math.add(math.pw(z, 2), fractal->complex);
		if (math.abs(z) > fractal->threshold)
		{
			return (0); // Assuming image data is a 1D array
			break ;
		}
	}
	return (1);
}
