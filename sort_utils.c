/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrherna <adrianhdt.2001@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:03:00 by adrherna          #+#    #+#             */
/*   Updated: 2024/05/27 10:15:18 by adrherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

int	square_root(int num)
{
	int	start;
	int	end;
	int	mid;
	int	root;

	if (num == 0 || num == 1)
		return (num);
	start = 1;
	end = num / 2;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid <= num / mid)
		{
			start = mid + 1;
			root = mid;
		}
		else
			end = mid - 1;
	}
	return (root);
}
