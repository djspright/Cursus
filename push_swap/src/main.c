/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 23:38:02 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/21 23:38:21 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_sort_algorithm(t_data *data)
{
	if (is_sorted(data->a))
		return ;
	if (data->a->size <= 3)
		sort_three(data);
	else if (data->a->size <= 100)
		sort_small(data);
	else
		sort_large(data);
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	data = parse_args(argc, argv);
	if (!data)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	choose_sort_algorithm(data);
	free_data(data);
	return (0);
}
