/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:52:09 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 13:26:03 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_lst **a)
{
	t_lst	*tmp;
	t_lst	*last;

	if (*a && (*a)->next)
	{
		last = list_last(*a);
		last->next = (*a);
		tmp = (*a)->next;
		(*a)->next = NULL;
		(*a) = tmp;
	}
}

void	ra(t_lst **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_lst **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_lst **a, t_lst **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
