/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:58:11 by adrherna          #+#    #+#             */
/*   Updated: 2024/06/03 12:33:58 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_contains_number(t_stack *head, long num)
{
	t_stack	*current;

	if (head == NULL)
		return (false);
	current = head;
	if (current->num == num)
		return (true);
	current = current->next;
	while (current != head)
	{
		if (current->num == num)
			return (true);
		current = current->next;
	}
	return (false);
}

t_stack	*add_or_init_node(t_stack **head, long num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->num = num;
	if (*head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		new_node->prev = (*head)->prev;
		(*head)->prev->next = new_node;
		(*head)->prev = new_node;
	}
	return (*head);
}

long	ft_strtol(const char *str)
{
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	return (nb * sign);
}

bool	ft_is_invalid(const char *str)
{
	while (*str == 32)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (true);
	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == 32)
		str++;
	if (*str != '\0')
		return (true);
	return (false);
}

bool	process_args(char *arg, t_stack	**head_a)
{
	long	num;
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(arg, ' ');
	while (nums[i] != NULL)
	{
		num = ft_strtol(nums[i]);
		if (ft_is_invalid(nums[i]) || ft_contains_number(*head_a, num)
			|| ft_bigger_than_int(num))
		{
			free_split(nums);
			return (true);
		}
		add_or_init_node(head_a, num);
		i++;
	}
	free_split(nums);
	return (false);
}
