/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 16:22:59 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:05:32 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_lst **a)
{
	t_lst	*pre_last;
	t_lst	*tmp;

	if (*a && (*a)->next)
	{		
		tmp = (*a);
		while (tmp->next->next)
			tmp = tmp->next;
		pre_last = tmp;
		tmp = pre_last->next;
		pre_last->next = NULL;
		tmp->next = (*a);
		(*a) = tmp;
	}
}

void	rra(t_lst **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_lst **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/****** reverse rotate both stacks a and b ********/
void	rrr(t_lst **a, t_lst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
