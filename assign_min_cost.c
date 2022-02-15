/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_min_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:33:55 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/03 19:07:42 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**********find current min and max numbers in stack a****************/
void	find_local_min_max(t_lst *lst, t_values *val)
{
	val->min = lst->number;
	val->max = lst->number;
	while (lst)
	{
		if (val->min > lst->number)
			val->min = lst->number;
		if (val->max < lst->number)
			val->max = lst->number;
		lst = lst->next;
	}
}

/********assign min cost of rortates in stack a**********************/
int	assign_ra_rra_cost(t_lst *a, t_lst *b, t_values *val)
{
	int		i;

	i = 0;
	find_local_min_max(a, val);
	if ((b->number > val->max) || (b->number < val->min))
		return (assign_rotation_cost(a, val->min));
	if (b->number < a->number && b->number > list_last(a)->number)
		return (0);
	while (a)
	{
		if (b->number > a->number && b->number < a->next->number)
			return (i + 1);
		i++;
		a = a->next;
	}
	return (i);
}

/********assign min cost to push from b to a stack******************/
void	assign_min_cost(t_lst *a, t_lst *b, t_values *val)
{
	t_lst	*top;
	int		min;

	top = b;
	while (b)
	{
		min = 0;
		b->rb_cost = assign_rotation_cost(top, b->number);
		b->rrb_cost = val->b_lst_len - b->rb_cost;
		if (b->rb_cost < b->rrb_cost)
			min = b->rb_cost;
		else
			min = b->rrb_cost;
		b->ra_cost = assign_ra_rra_cost(a, b, val);
		b->rra_cost = val->a_lst_len - b->ra_cost;
		if (b->ra_cost < b->rra_cost)
			b->min = b->ra_cost + min;
		else
			b->min = b->rra_cost + min;
		b = b->next;
	}
}
