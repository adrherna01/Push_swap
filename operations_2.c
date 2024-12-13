/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:58:36 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/26 11:32:27 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, t_stack_data *data)
{
	rotate(stack_a);
	ft_find_min_max_a(stack_a, data);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, t_stack_data *data)
{
	rotate(stack_b);
	ft_find_min_max_b(stack_b, data);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_stack_data *data)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_find_min_max_a(stack_a, data);
	ft_find_min_max_b(stack_b, data);
	write(1, "rr\n", 3);
}
