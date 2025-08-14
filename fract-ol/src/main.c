/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:28:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 17:13:15 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [options]\n", 1);
	ft_putstr_fd("Fractals:\n", 1);
	ft_putstr_fd("  mandelbrot\n", 1);
	ft_putstr_fd("  julia <real> <imag>\n", 1);
}

static int	parse_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		fractal->fractal_type = MANDELBROT;
		return (1);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
	{
		fractal->fractal_type = JULIA;
		fractal->julia_c.real = ft_atof(argv[2]);
		fractal->julia_c.imag = ft_atof(argv[3]);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (!parse_arguments(argc, argv, &fractal))
	{
		print_usage();
		return (1);
	}
	init_fractal(&fractal);
	render_fractal(&fractal);
	setup_hooks(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
