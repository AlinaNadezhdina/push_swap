/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:39:09 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:11:10 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_value_struct(t_values *val)

{
	val->lst_len = 0;
	val->max = 0;
	val->mediana = 0;
	val->min = 0;
}

void	sort_all(t_lst **a, t_lst **b, t_values val)
{
	make_3_elements_in_stack(a, b, &val);
	sort_3_elements(a, &val);
	if (val.lst_len > 3)
		pop_from_b_stack(a, b, val);
	pop_min_to_the_top(a, val);
}

int	main(int argc, char **argv)
{
	t_lst		*a;
	t_lst		*b;
	t_values	val;

	b = NULL;
	if (argc == 1)
		return (0);
	init_value_struct(&val);
	parse_args(&argv[1], &a, &val);
	if (is_list_sorted(a))
	{
		list_clear(&a);
		return (0);
	}
	fill_values_struct(a, &val);
	if (val.lst_len == 2)
		sort_3_elements(&a, &val);
	if (val.lst_len >= 3)
		sort_all(&a, &b, val);
	list_clear(&a);
	return (0);
}
