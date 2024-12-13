/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:19 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/27 10:12:18 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	ft_num_search(int *array, int num, t_stack_data *data)
{
	int	i;

	i = 0;
	while (i < data->stack_size_a)
	{
		if (array[i] == num)
			break ;
		i++;
	}
	return (i);
}

void	ft_should_index(t_stack **stack_a, t_stack_data *data, int *array)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = (*stack_a);
	while (true)
	{
		current->should_index = ft_num_search(array, current->num, data);
		current = current->next;
		if (current == *stack_a)
			break ;
	}
}

int	*ft_assign_array(t_stack **stack_a, t_stack_data *data)
{
	int		i;
	int		*array;
	t_stack	*current;

	i = 0;
	array = malloc(sizeof(int) * data->stack_size_a);
	current = (*stack_a);
	while (true)
	{
		array[i] = current->num;
		current = current->next;
		if (current == *stack_a)
			break ;
		i++;
	}
	ft_bubble_sort(array, data);
	return (array);
}

void	ft_bubble_sort(int	*array, t_stack_data *data)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < data->stack_size_a - 1)
	{
		j = 0;
		while (j < data->stack_size_a - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_stack_size(t_stack **stack_a, t_stack_data *data)
{
	t_stack	*current;

	if (stack_a == NULL || *stack_a == NULL)
	{
		data->stack_size_a = 0;
		return ;
	}
	current = (*stack_a);
	while (true)
	{
		data->stack_size_a++;
		current = current->next;
		if (current == *stack_a)
			break ;
	}
}
