/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:22:28 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/15 13:57:36 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bind_nodes(t_stack *node_to_move, t_stack **stack_src)
{
	node_to_move->prev->next = node_to_move->next;
	node_to_move->next->prev = node_to_move->prev;
	*stack_src = node_to_move->next;
}

void	ft_first_node(t_stack *node_to_move, t_stack **stack_dst)
{
	node_to_move->next = node_to_move;
	node_to_move->prev = node_to_move;
	*stack_dst = node_to_move;
}

void	ft_insert_node(t_stack *node_to_move, t_stack **stack_dst)
{
	node_to_move->next = *stack_dst;
	node_to_move->prev = (*stack_dst)->prev;
	(*stack_dst)->prev->next = node_to_move;
	(*stack_dst)->prev = node_to_move;
	*stack_dst = node_to_move;
}

void	push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*node_to_move;

	node_to_move = *stack_src;
	if (stack_src == NULL || *stack_src == NULL)
		return ;
	if (node_to_move->next == node_to_move)
		*stack_src = NULL;
	else
		ft_bind_nodes(node_to_move, stack_src);
	if (*stack_dst == NULL)
		ft_first_node(node_to_move, stack_dst);
	else
		ft_insert_node(node_to_move, stack_dst);
}
