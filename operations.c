/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:24:10 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/21 11:18:33 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// , t_stack **stack_b

void	sa(t_stack **stack_a, t_stack_data *data)
{
	swap(stack_a);
	ft_find_min_max_a(stack_a, data);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, t_stack_data *data)
{
	swap(stack_b);
	ft_find_min_max_b(stack_b, data);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	swap(stack_a);
	swap(stack_b);
	ft_find_min_max_a(stack_a, data);
	ft_find_min_max_b(stack_b, data);
	write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	push(stack_b, stack_a);
	data->stack_size_a += 1;
	data->stack_size_b -= 1;
	ft_find_min_max_a(stack_a, data);
	ft_find_min_max_b(stack_b, data);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	push(stack_a, stack_b);
	data->stack_size_a -= 1;
	data->stack_size_b += 1;
	ft_find_min_max_a(stack_a, data);
	ft_find_min_max_b(stack_b, data);
	write(1, "pb\n", 3);
}
