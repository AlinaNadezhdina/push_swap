/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional_sort_3_elem.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:33:25 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 12:24:54 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_3_elements_in_stack(t_lst **a, t_lst **b, t_values *val)
{
	int	count;

	val->b_lst_len = 0;
	count = val->lst_len;
	while (count > 3)
	{
		pb(a, b);
		if (val->b_lst_len > 1 && (*b)->number > val->mediana)
			rb(b);
		count--;
		val->b_lst_len++;
	}
	val->a_lst_len = 3;
}

void	sort_3_elements(t_lst **a, t_values *val)
{
	int		local_med;
	t_lst	*tmp;

	find_local_min_max(*a, val);
	tmp = *a;
	local_med = tmp->number;
	while (tmp)
	{
		if (tmp->number != val->min && tmp->number != val->max)
			local_med = tmp->number;
		tmp = tmp->next;
	}
	if (((*a)->number == val->min && (*a)->next->number == val->max)
		|| ((*a)->number == local_med && (*a)->next->number == val->min)
		|| ((*a)->number == val->max && (*a)->next->number == local_med))
		sa(a);
}
