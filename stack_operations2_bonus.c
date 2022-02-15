/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:49:20 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 13:44:05 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/****** swap both stacks a and b ********/
void	ss(t_lst	**a, t_lst	**b)
{
	swap(a);
	swap(b);
}

/****** rotate both stacks a and b ********/
void	rr(t_lst **a, t_lst **b)
{
	rotate(a);
	rotate(b);
}

/****** reverse rotate both stacks a and b ********/
void	rrr(t_lst **a, t_lst **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
