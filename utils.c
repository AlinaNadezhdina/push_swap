/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:08:07 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 13:46:20 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/****assign rotation cost for stack item *****/
int	assign_rotation_cost(t_lst	*a, int item)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->number != item)
			i++;
		else
			return (i);
		a = a->next;
	}
	return (i);
}

/******repeat rotates in one stack****************/
void	repeat_1_arg_operation(int count, t_lst **s1, void (*func)(t_lst **))
{
	while (count > 0)
	{
		func(s1);
		count--;
	}
}

/******repeat rotates in two stacks****************/
void	repeat_2_arg_operation(int count, t_lst **s1, t_lst **s2,
			void (*func)(t_lst **, t_lst **))
{
	while (count > 0)
	{
		func(s1, s2);
		count--;
	}
}

/***********find element with min cost in stack b***********/
t_lst	*find_min_cost_item(t_lst *b)
{
	t_lst	*tmp;

	tmp = b;
	while (b && b->next)
	{
		if (tmp->min > b->next->min)
			tmp = b->next;
		b = b->next;
	}
	return (tmp);
}
