/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:01:15 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/31 12:17:39 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_find_min_max_a(t_stack **stack_a, t_stack_data *data)
{
	t_stack	*current;

	if (*stack_a == NULL)
	{
		data->max_a = -1;
		data->min_a = -1;
		return ;
	}
	current = (*stack_a)->next;
	data->min_a = (*stack_a)->num;
	data->max_a = (*stack_a)->num;
	while (current != *stack_a)
	{
		if (current->num > data->max_a)
			data->max_a = current->num;
		if (current->num < data->min_a)
			data->min_a = current->num;
		current = current->next;
	}
}

void	ft_find_min_max_b(t_stack **stack_b, t_stack_data *data)
{
	t_stack	*current;

	if (*stack_b == NULL)
	{
		data->max_b = -1;
		data->min_b = -1;
		return ;
	}
	current = (*stack_b)->next;
	data->min_b = (*stack_b)->num;
	data->max_b = (*stack_b)->num;
	while (current != *stack_b)
	{
		if (current->num > data->max_b)
			data->max_b = current->num;
		if (current->num < data->min_b)
			data->min_b = current->num;
		current = current->next;
	}
}

void	ft_array(t_stack **stack_a, t_stack_data *data)
{
	int	*array;

	ft_stack_size(stack_a, data);
	array = ft_assign_array(stack_a, data);
	ft_should_index(stack_a, data, array);
	free(array);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	ft_array(stack_a, data);
	ft_sort(stack_a, stack_b, data);
}
