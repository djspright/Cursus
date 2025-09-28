/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 23:35:45 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 16:40:47 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				*array;
	int				head;
	int				size;
	int 			capacity;
}					t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				total_size;
}					t_data;

/* Operations */
void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	pa(t_data *data, int print);
void	pb(t_data *data, int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);

void	sort_three(t_data *data);
void	sort_small(t_data *data);
void	sort_large(t_data *data);
void	compress_values(t_data *data);

int		is_sorted(t_stack *stack);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
void	free_data(t_data *data);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

/* Stack management */
t_stack	*stack_init(int capacity);
t_data	*data_init(int capacity);
void	stack_free(t_stack *stack);

/* Parsing */
t_data	*parse_args(int argc, char **argv);
int		validate_args(int argc, char **argv);

#endif
