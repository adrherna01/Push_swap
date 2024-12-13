/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:52:55 by adrherna          #+#    #+#             */
/*   Updated: 2024/06/03 12:43:30 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// void	leaks(void)
// {
// 	system("leaks push_swap");
// }

bool	ft_bigger_than_int(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (true);
	return (false);
}

void	init_variables(int *i, int *j, t_stack **head_a, t_stack **head_b)
{
	*i = 1;
	*j = 0;
	*head_a = NULL;
	*head_b = NULL;
}

t_stack_data	*init_struct(t_stack **stack_a)
{
	t_stack			*current;
	t_stack_data	*data;

	current = *stack_a;
	data = malloc(sizeof(t_stack_data));
	if (!data)
		return (NULL);
	data->max_a = current->num;
	data->min_a = current->num;
	data->stack_size_a = 0;
	data->stack_size_b = 0;
	return (data);
}

int	main(int argc, char *argv[])
{
	t_stack			*head_a;
	t_stack			*head_b;
	t_stack_data	*data;
	int				i;
	int				j;

	if (argc < 2)
		return (0);
	init_variables(&i, &j, &head_a, &head_b);
	data = NULL;
	while (i < argc)
	{
		if (process_args(argv[i], &head_a))
		{
			manage_error(&head_a, &head_b, data);
			return (-1);
		}
		i++;
	}
	data = init_struct(&head_a);
	if (ft_is_sorted(&head_a))
		return (0);
	algorithm(&head_a, &head_b, data);
	free_all(&head_a, &head_b, data);
	return (0);
}
