/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shacker_sort_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:09:02 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:02:09 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	init_sort_struct(t_sort *sort, int length)
{
	sort->i = 0;
	sort->left = 0;
	sort->right = length;
	sort->swap_fl = 1;
}

void	shacker_sort(int *arr, t_sort s)
{
	while (s.swap_fl && s.left < s.right)
	{
		s.swap_fl = 0;
		s.i = s.left;
		while (s.i < s.right)
		{
			if (arr[s.i] > arr[s.i + 1])
			{
				s.swap_fl = 1;
				swap_int(&arr[s.i], &arr[s.i + 1]);
			}	
			s.i++;
		}
		s.i = --s.right;
		while (s.i > s.left)
		{
			if (arr[s.i] < arr[s.i - 1])
			{
				s.swap_fl = 1;
				swap_int(&arr[s.i], &arr[s.i - 1]);
			}	
			s.i--;
		}
		s.left++;
	}
}

void	fill_values_struct(t_lst *begin, t_values *val)
{
	t_lst	*tmp;
	t_sort	sort;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * val->lst_len);
	tmp = begin;
	i = -1;
	while (tmp)
	{
		arr[++i] = tmp->number;
		tmp = tmp->next;
	}
	init_sort_struct(&sort, val->lst_len - 1);
	shacker_sort(arr, sort);
	val->mediana = arr[(val->lst_len - 1) / 2];
	free(arr);
}
