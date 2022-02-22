/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:18:02 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:12:09 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*****assign cost of rotates to put min element in stack a on the top*****/
void	pop_min_to_the_top(t_lst	**a, t_values val)
{
	int	cost_r_a;
	int	cost_rr_a;

	find_local_min_max(*a, &val);
	cost_r_a = assign_rotation_cost(*a, val.min);
	cost_rr_a = val.lst_len - cost_r_a;
	while ((*a) && (*a)->number != val.min)
	{
		if ((*a)->number > val.min)
		{
			if (cost_r_a <= cost_rr_a)
				ra(a);
			else
				rra(a);
		}
		else
			return ;
	}	
}

void	make_ra_rotation(t_lst *tmp, t_lst **a_begin, t_lst **b_begin)
{
	int	count;

	if (tmp->rb_cost <= tmp->rrb_cost)
	{
		if (tmp->ra_cost >= tmp->rb_cost)
		{
			count = tmp->ra_cost - tmp->rb_cost;
			repeat_2_arg_operation(tmp->rb_cost, a_begin, b_begin, rr);
			repeat_1_arg_operation(count, a_begin, ra);
		}
		else
		{
			count = tmp->rb_cost - tmp->ra_cost;
			repeat_2_arg_operation(tmp->ra_cost, a_begin, b_begin, rr);
			repeat_1_arg_operation(count, b_begin, rb);
		}
	}
	else
	{
		repeat_1_arg_operation(tmp->ra_cost, a_begin, ra);
		repeat_1_arg_operation(tmp->rrb_cost, b_begin, rrb);
	}
}

void	make_rra_rotation(t_lst *tmp, t_lst **a_begin, t_lst **b_begin)
{
	int	count;

	if (tmp->rb_cost <= tmp->rrb_cost)
	{
		repeat_1_arg_operation(tmp->rra_cost, a_begin, rra);
		repeat_1_arg_operation(tmp->rb_cost, b_begin, rb);
	}
	else
	{
		if (tmp->rra_cost >= tmp->rrb_cost)
		{
			count = tmp->rra_cost - tmp->rrb_cost;
			repeat_2_arg_operation(tmp->rrb_cost, a_begin, b_begin, rrr);
			repeat_1_arg_operation(count, a_begin, rra);
		}
		else
		{
			count = tmp->rrb_cost - tmp->rra_cost;
			repeat_2_arg_operation(tmp->rra_cost, a_begin, b_begin, rrr);
			repeat_1_arg_operation(count, b_begin, rrb);
		}
	}
}

void	push_in_a_stack(t_lst **a_begin, t_lst **b_begin)
{
	t_lst	*tmp;

	tmp = find_min_cost_item(*b_begin);
	if (tmp->ra_cost <= tmp->rra_cost)
		make_ra_rotation(tmp, a_begin, b_begin);
	else
		make_rra_rotation(tmp, a_begin, b_begin);
	pa(b_begin, a_begin);
}

void	pop_from_b_stack(t_lst **a, t_lst **b, t_values val)
{
	while (*b)
	{
		assign_min_cost(*a, *b, &val);
		push_in_a_stack(a, b);
		val.b_lst_len--;
		val.a_lst_len++;
	}
}
