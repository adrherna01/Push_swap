/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:45:24 by adrherna          #+#    #+#             */
/*   Updated: 2024/06/03 12:43:20 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_a(t_stack **head_a)
{
	t_stack	*current;
	t_stack	*next_node;

	if (*head_a != NULL)
	{
		current = *head_a;
		while (current->next != *head_a)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		free(current);
		*head_a = NULL;
	}
}

void	free_b(t_stack **head_b)
{
	t_stack	*current;
	t_stack	*next_node;

	if (*head_b != NULL)
	{
		current = *head_b;
		while (current->next != *head_b)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		free(current);
		*head_b = NULL;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_all(t_stack **head_a, t_stack **head_b, t_stack_data	*data)
{
	free_a(head_a);
	free_b(head_b);
	if (data != NULL)
		free(data);
}

void	manage_error(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	ft_putstr_fd("Error\n", 2);
	free_all(stack_a, stack_b, data);
}
