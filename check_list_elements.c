/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:01:11 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/22 10:28:48 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_there_dubles(t_lst *begin)
{
	t_lst	*tmp;
	t_lst	*tmp1;

	tmp = begin;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (tmp->number == tmp1->number)
				return (1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	check_is_digit_or_space_or_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == ' '\
		|| s[i] == '+' || s[i] == '-')
			i++;
		else
			ft_exit();
	}
}

int	is_list_sorted(t_lst *begin)
{
	t_lst	*tmp;

	tmp = begin;
	while (tmp && tmp->next)
	{
		if (tmp->number < tmp->next->number)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}
