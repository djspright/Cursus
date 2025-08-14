/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:28:59 by shkondo           #+#    #+#             */
/*   Updated: 2025/08/14 11:28:15 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int validate_args(char *str)
{
	float value;

	if (!str || !*str)
		return 0;
	value = ft_atof(str);
	return (value != 0);
}

int	main(int ac, char **av)
{
		t_fractal fractal;
		t_image image;

	if (ac == 4)
	{
		if (!validate_args(av[2]) || !validate_args(av[3]))
		{
			write(2, "Invalid arguments\n", 18);
			return (1);
		}
	}
	else
	{
		write(2, "Usage: ./fractol <fractal_type> <center> <magnification>\n",
			58);
		return (1);
	}
	return (0);
}
