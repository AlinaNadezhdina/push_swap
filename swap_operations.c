/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:10:36 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 13:44:38 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_lst(t_lst **elem)
{
	t_lst	*tmp;

	if ((*elem) && (*elem)->next)
	{
		tmp = (*elem)->next;
		(*elem)->next = tmp->next;
		tmp->next = (*elem);
		*elem = tmp;
	}
}

void	sa(t_lst	**elem)
{
	swap_lst(elem);
	write(1, "sa\n", 3);
}

void	sb(t_lst	**elem)
{
	swap_lst(elem);
	write(1, "sb\n", 3);
}

void	ss(t_lst	**a, t_lst	**b)
{
	swap_lst(a);
	swap_lst(b);
	write(1, "ss\n", 3);
}
