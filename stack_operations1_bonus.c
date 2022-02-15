/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:46:16 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 13:41:42 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/******** push elememnt from stack a to stack b *****/
void	push(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	if ((*a) != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = tmp;
	}
}

void	swap(t_lst **a)
{
	t_lst	*tmp;

	if ((*a) && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = (*a);
		*a = tmp;
	}
}

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
