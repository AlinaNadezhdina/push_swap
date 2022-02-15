/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:41:19 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 13:24:11 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

typedef struct s_values
{
	int	max;
	int	min;
	int	mediana;
	int	lst_len;
	int	b_lst_len;
	int	a_lst_len;
}t_values;

typedef struct s_sort
{
	int	left;
	int	right;
	int	swap_fl;
	int	i;
}t_sort;

t_lst	*create_new_list(int num, t_values *val);
void	list_add_back(t_lst **lst, t_lst *new);
void	list_clear(t_lst **lst);
t_lst	*list_last(t_lst *lst);
void	ft_exit(void);
int		is_there_dubles(t_lst *begin);
void	check_is_digit_or_space_or_sign(char *s);
int		is_list_sorted(t_lst *begin);
void	parse_args(char **args, t_lst **begin, t_values *val);
void	fill_values_struct(t_lst *begin, t_values *val);
void	sa(t_lst	**elem);
void	sb(t_lst	**elem);
void	ss(t_lst	**a, t_lst	**b);
void	pa(t_lst **b, t_lst **a);
void	pb(t_lst **a, t_lst **b);
void	ra(t_lst **a);
void	rb(t_lst **b);
void	rr(t_lst **a, t_lst **b);
void	rra(t_lst **a);
void	rrb(t_lst **b);
void	rrr(t_lst **a, t_lst **b);
void	make_3_elements_in_stack(t_lst **a, t_lst **b, t_values *val);
void	sort_3_elements(t_lst **a, t_values *val);
void	assign_min_cost(t_lst *a, t_lst *b, t_values *val);
void	pop_min_to_the_top(t_lst	**a, t_values val);
int		assign_rotation_cost(t_lst	*a, int item);
t_lst	*find_min_cost_item(t_lst *b);
void	repeat_1_arg_operation(int count, t_lst **s1, void (*func)(t_lst **));
void	repeat_2_arg_operation(int count, t_lst **s1, t_lst **s2,
			void (*func)(t_lst **, t_lst **));
void	pop_from_b_stack(t_lst **a, t_lst	**b, t_values val);
void	find_local_min_max(t_lst *lst, t_values *val);
int		my_atoi(const char *str);
#endif