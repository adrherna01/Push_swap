/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:56:27 by adrherna          #+#    #+#             */
/*   Updated: 2024/06/03 12:42:46 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	long			num;
	int				should_index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stack_data
{
	int	max_a;
	int	min_a;
	int	max_b;
	int	min_b;
	int	stack_size_a;
	int	stack_size_b;
}	t_stack_data;

// main.c

t_stack_data	*init_struct(t_stack **stack_a);
bool			ft_bigger_than_int(long num);

// arg_utils.c :

t_stack			*add_or_init_node(t_stack **head, long num);
bool			ft_contains_number(t_stack *head, long num);
long			ft_strtol(const char *str);
bool			ft_is_invalid(const char *str);
bool			process_args(char *arg, t_stack **head);

// push.c :

void			ft_bind_nodes(t_stack *node_to_move, t_stack **stack_src);
void			ft_first_node(t_stack *node_to_move, t_stack **stack_dst);
void			ft_insert_node(t_stack *node_to_move, t_stack **stack_dst);
void			push(t_stack **stack_src, t_stack **stack_dst);

// swap.c

void			swap(t_stack **head);
void			rotate(t_stack **head);
void			rev_rotate(t_stack **head);

// operations.c

void			sa(t_stack **stack_a, t_stack_data *data);
void			sb(t_stack **stack_b, t_stack_data *data);
void			ss(t_stack **stack_a, t_stack **stack_b, t_stack_data *data);
void			pa(t_stack **stack_a, t_stack **stack_b, t_stack_data *data);
void			pb(t_stack **stack_a, t_stack **stack_b, t_stack_data *data);

// operations_2.c

void			ra(t_stack **stack_a, t_stack_data *data);
void			rb(t_stack **stack_b, t_stack_data *data);
void			rr(t_stack **stack_a, t_stack **stack_b, t_stack_data *data);

// operations_3.c

void			rra(t_stack **stack_a, t_stack_data *data);
void			rrb(t_stack **stack_b, t_stack_data *data);
void			rrr(t_stack **stack_a, t_stack **stack_b, t_stack_data *data);

// algorithm.c

void			ft_find_min_max_a(t_stack **stack_a, t_stack_data *data);
void			ft_find_min_max_b(t_stack **stack_b, t_stack_data *data);
void			ft_array(t_stack **stack_a, t_stack_data *data);
void			algorithm(t_stack **stack_a, t_stack **stack_b,
					t_stack_data *data);

// array.c

int				ft_num_search(int *array, int num, t_stack_data *data);
int				*ft_assign_array(t_stack **stack_a, t_stack_data *data);
void			ft_bubble_sort(int *array, t_stack_data *data);
void			ft_stack_size(t_stack **stack_a, t_stack_data *data);
void			ft_should_index(t_stack **stack_a, t_stack_data *data,
					int *array);

// sort.c

int				ft_calc_up(t_stack **stack_b, t_stack_data *data);
int				ft_calc_down(t_stack **stack_b, t_stack_data *data);
void			ft_back_to_a(t_stack **stack_a, t_stack **stack_b,
					t_stack_data *data);
void			ft_big_sort(t_stack **stack_a, t_stack **stack_b,
					t_stack_data *data);
void			ft_sort(t_stack **stack_a, t_stack **stack_b,
					t_stack_data *data);

// sort_2.c

int				ft_is_sorted(t_stack **stack_a);
void			ft_rot_to_top(t_stack **stack_a, t_stack_data *data);
void			ft_sort_3(t_stack **stack_a, t_stack **stack_b,
					t_stack_data *data);
void			ft_sort_5(t_stack **stack_a, t_stack **stack_b,
					t_stack_data *data);

//sort_utils.c

int				square_root(int x);

// free.c

void			free_a(t_stack **head_a);
void			free_b(t_stack **head_b);
void			free_split(char **split);
void			free_all(t_stack **head_a, t_stack **head_b,
					t_stack_data *data);
void			manage_error(t_stack **stack_a, t_stack **stack_b,
					t_stack_data *data);

#endif