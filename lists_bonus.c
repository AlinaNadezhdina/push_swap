/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:06:32 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:08:02 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_lst	*create_new_list(int num)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (new)
	{
		new->number = num;
		new->next = NULL;
	}
	return (new);
}

t_lst	*list_last(t_lst *lst)
{
	while (lst)
	{
		if (lst->next == (void *)0)
			return (lst);
		lst = lst->next;
	}
	return ((t_lst *)0);
}

void	list_add_back(t_lst **lst, t_lst *new)
{
	t_lst	*last_elem;

	if (*lst)
	{
		last_elem = list_last(*lst);
		last_elem->next = new;
	}
	else
	{
		*lst = new;
	}
}

void	list_clear(t_lst **lst)
{
	t_lst	*temp;
	t_lst	*list;

	list = *lst;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	*lst = (void *)0;
}
