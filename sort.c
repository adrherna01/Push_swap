/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:50:48 by adrherna          #+#    #+#             */
/*   Updated: 2024/06/03 10:21:29 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>

int	ft_calc_up(t_stack **stack_b, t_stack_data *data)
{
	t_stack	*current;
	int		moves;

	moves = 0;
	current = (*stack_b);
	while (true)
	{
		if (current->num == data->max_b)
			break ;
		current = current->next;
		moves++;
		if (current->next == (*stack_b))
			break ;
	}
	return (moves);
}

int	ft_calc_down(t_stack **stack_b, t_stack_data *data)
{
	t_stack	*current;
	int		moves;

	moves = 0;
	current = (*stack_b);
	while (true)
	{
		if (current->num == data->max_b)
			break ;
		current = current->prev;
		moves++;
		if (current->prev == (*stack_b))
			break ;
	}
	return (moves);
}

void	ft_back_to_a(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	int	moves_up;
	int	moves_down;

	while (data->stack_size_b != 0)
	{
		moves_up = ft_calc_up(stack_b, data);
		moves_down = ft_calc_down(stack_b, data);
		if (moves_up < moves_down)
			while (moves_up--)
				rb(stack_b, data);
		else
			while (moves_down--)
				rrb(stack_b, data);
		pa(stack_a, stack_b, data);
	}
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	t_stack	*current;
	int		index;
	int		range;

	range = (square_root(data->stack_size_a) * 14) / 10;
	current = (*stack_a);
	index = 0;
	while (data->stack_size_a != 0)
	{
		if (current->should_index <= index)
		{
			pb(stack_a, stack_b, data);
			rb(stack_b, data);
			index++;
		}
		else if (current->should_index <= index + range)
		{
			pb(stack_a, stack_b, data);
			index++;
		}
		else
			ra(stack_a, data);
		current = (*stack_a);
	}
	ft_back_to_a(stack_a, stack_b, data);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	if (data->stack_size_a == 2)
		sa(stack_a, data);
	else if (data->stack_size_a == 3)
		ft_sort_3(stack_a, stack_b, data);
	else if (data->stack_size_a > 3 && data->stack_size_a <= 5)
		ft_sort_5(stack_a, stack_b, data);
	else
		ft_big_sort(stack_a, stack_b, data);
}
