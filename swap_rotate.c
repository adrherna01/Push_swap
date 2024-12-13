/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:55:53 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/16 11:49:17 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (*head == NULL || (*head)->next == *head)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = first->prev;
	first->prev->next = second;
	first->prev = second;
	*head = second;
}

void	rotate(t_stack **head)
{
	if (*head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->next;
}

void	rev_rotate(t_stack **head)
{
	if (*head == NULL || (*head)->next == *head)
		return ;
	*head = (*head)->prev;
}
