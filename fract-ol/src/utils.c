/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 11:09:31 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/19 14:31:02 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		fraction = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i++] - '0') * fraction;
			fraction *= 0.1;
		}
	}
	return (result * sign);
}

double	map_range(double value, double old_min, double old_max, double new_min,
		double new_max)
{
	return ((value - old_min) * (new_max - new_min) / (old_max - old_min)
		+ new_min);
}

int	color_interpolate(int start_color, int end_color, double t)
{
	int	start_r;
	int	start_g;
	int	start_b;
	int	r;
	int	g;
	int	b;
	int	end_r;
	int	end_g;
	int	end_b;

	start_r = (start_color >> 16) & 0xFF;
	start_g = (start_color >> 8) & 0xFF;
	start_b = start_color & 0xFF;
	end_r = (end_color >> 16) & 0xFF;
	end_g = (end_color >> 8) & 0xFF;
	end_b = end_color & 0xFF;
	r = (int)((1 - t) * start_r + t * end_r);
	g = (int)((1 - t) * start_g + t * end_g);
	b = (int)((1 - t) * start_b + t * end_b);
	return (r << 16 | g << 8 | b);
}

void	cleanup_exit(t_fractal *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		// mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
}

void	error_exit(const char *message, t_fractal *fractal)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd((char *)message, 2);
	ft_putstr_fd("\n", 2);
	cleanup_exit(fractal);
}
