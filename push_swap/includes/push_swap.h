/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkondo <shkondo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 23:35:45 by shkondo           #+#    #+#             */
/*   Updated: 2025/09/28 20:23:43 by shkondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node		*head;
	int			size;
}				t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		total_size;
}			t_data;

/* Operations */
void		sa(t_data *data, int print);
void		sb(t_data *data, int print);
void		ss(t_data *data, int print);
void		pa(t_data *data, int print);
void		pb(t_data *data, int print);
void		ra(t_data *data, int print);
void		rb(t_data *data, int print);
void		rr(t_data *data, int print);
void		rra(t_data *data, int print);
void		rrb(t_data *data, int print);
void		rrr(t_data *data, int print);

void		sort_three(t_data *data);
void		sort_small(t_data *data);
void		sort_large(t_data *data);
void		radix_sort(t_data *data);
void		optimized_radix_sort(t_data *data);
void		quick_sort(t_data *data);
void		quick_sort_b(t_data *data, int size);
void		quick_sort_a(t_data *data, int size);
void		optimized_quick_sort(t_data *data);
void		improved_quick_sort(t_data *data);
void		recursive_quick_sort(t_data *data);
void		handle_small_a(t_data *data, int size);
void		handle_small_b(t_data *data, int size);
void		advanced_quick_sort(t_data *data);
void		advanced_quick_sort_a(t_data *data, int size, int depth);
void		advanced_quick_sort_b(t_data *data, int size, int depth);
void		simple_push_to_b(t_data *data, int size);
void		handle_small_sort_a(t_data *data, int size);
void		handle_small_sort_b(t_data *data, int size);
void		compress_values(t_data *data);
void		rotate_to_top(t_data *data, int min_idx);
void		sort_four(t_data *data);
void		sort_five_optimized(t_data *data);
void		optimized_radix_pass(t_data *data, int bit_pos);
int			count_bits_needed(int max_val);
void		smart_push_back(t_data *data);

/* Chunk Sort Algorithm */
void		push_back_sorted_from_b(t_data *data);
void		final_rotation(t_data *data);
int			calculate_adaptive_size(int chunk_size, int i, int chunk_count);

/* Quick Sort Algorithm */
int			get_pivot_b(t_data *data, int size);
void		sort_top_three(t_data *data);
int			get_smart_pivot(t_data *data, t_stack *stack, int size);

int			is_sorted(t_stack *stack);
int			find_min_index(t_stack *stack);
int			find_max_index(t_stack *stack);
int			find_second_min_index(t_stack *stack);
void		free_data(t_data *data);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);

/* Stack management */
t_stack		*stack_init(void);
t_data		*data_init(int capacity);
void		stack_free(t_stack *stack);

/* Node management */
t_node		*create_node(int value);
void		push_front(t_stack *stack, int value);
void		push_back(t_stack *stack, int value);
int			pop_front(t_stack *stack);
int			pop_back(t_stack *stack);
int			get_at_index(t_stack *stack, int index);

/* Parsing */
t_data		*parse_args(int argc, char **argv);
int			validate_args(int argc, char **argv);
int			has_duplicates(int *array, int size);

/* Checker */
char		*get_next_line(void);
int			execute_operation(t_data *data, char *line);

#endif
