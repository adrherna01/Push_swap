/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:00:37 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/26 11:32:37 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, t_stack_data *data)
{
	rev_rotate(stack_a);
	ft_find_min_max_a(stack_a, data);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, t_stack_data *data)
{
	rev_rotate(stack_b);
	ft_find_min_max_b(stack_b, data);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_find_min_max_a(stack_a, data);
	ft_find_min_max_b(stack_b, data);
	write(1, "rrr\n", 4);
}
