/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:10:36 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 18:00:03 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*********** push push from stack b to stack a *****/
void	pa(t_lst **b, t_lst **a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

/*********** push from stack a to stack b *****/
void	pb(t_lst **a, t_lst **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
