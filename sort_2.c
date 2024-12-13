/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:16:40 by adrherna          #+#    #+#             */
/*   Updated: 2024/06/03 12:42:56 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_is_sorted(t_stack **stack_a)
{
	t_stack	*current;

	if (stack_a == NULL)
		return (1);
	current = (*stack_a);
	while (current->next != (*stack_a))
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_rot_to_top(t_stack	**stack_a, t_stack_data *data)
{
	t_stack	*current;
	long	rotations;

	rotations = 0;
	current = (*stack_a);
	while (current->num != data->min_a)
	{
		rotations++;
		current = current->next;
	}
	if (rotations <= data->stack_size_a / 2)
	{
		while (rotations--)
			ra(stack_a, data);
	}
	else
	{
		rotations = data->stack_size_a - rotations;
		while (rotations--)
			rra(stack_a, data);
	}
}

void	ft_sort_3(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	pb(stack_a, stack_b, data);
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a, data);
	if ((*stack_b)->num < (*stack_a)->num)
		pa(stack_a, stack_b, data);
	else if ((*stack_b)->num > (*stack_a)->num
		&& (*stack_b)->num > (*stack_a)->next->num)
	{
		pa(stack_a, stack_b, data);
		ra(stack_a, data);
	}
	else if ((*stack_b)->num > (*stack_a)->num)
	{
		pa(stack_a, stack_b, data);
		sa(stack_a, data);
	}
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	ft_find_min_max_a(stack_a, data);
	while (data->stack_size_a > 3)
	{
		ft_rot_to_top(stack_a, data);
		pb(stack_a, stack_b, data);
	}
	if (!ft_is_sorted(stack_a))
		ft_sort_3(stack_a, stack_b, data);
	while (data->stack_size_b != 0)
		pa(stack_a, stack_b, data);
}
