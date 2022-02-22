/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:38:14 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:24:49 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft/libft.h"
typedef struct s_lst
{
	int				number;
	struct s_lst	*next;
	int				ra_cost;
	int				rra_cost;
	int				rb_cost;
	int				rrb_cost;
	int				min;

}t_lst;

t_lst	*create_new_list(int num);
void	list_add_back(t_lst **lst, t_lst *new);
void	list_clear(t_lst **lst);
t_lst	*list_last(t_lst *lst);
void	ft_exit(void);
int		is_there_dubles(t_lst *begin);
void	check_is_digit_or_space_or_sign(char *s);
int		is_list_sorted(t_lst *a, t_lst *b);
void	parse_args(char **args, t_lst **begin);
void	swap(t_lst **a);
void	rotate(t_lst **a);
void	push(t_lst **a, t_lst **b);
void	reverse_rotate(t_lst **a);
void	ss(t_lst	**a, t_lst	**b);
void	rr(t_lst **a, t_lst **b);
void	rrr(t_lst **a, t_lst **b);
#endif
