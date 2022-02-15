/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:04:43 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/15 13:00:49 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_char_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_space(char s)
{
	if (s == ' ' || s == '\t' || s == '\n'
		|| s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

int	my_atoi(const char *str)
{
	int					sign;
	unsigned long int	number;

	sign = 1;
	number = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' || *str > '9')
		ft_exit();
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		if (number > 2147483647 && sign == 1)
			ft_exit();
		if (number > 2147483648 && sign == -1)
			ft_exit();
		str++;
	}
	if (*str && is_space(*str) == 0)
		ft_exit();
	return (number * sign);
}

void	parse_args(char **args, t_lst **begin)
{
	int		i;
	int		j;
	int		num;
	char	**str;
	t_lst	*list;

	i = -1;
	while (args[++i])
	{
		check_is_digit_or_space_or_sign(args[i]);
		str = ft_split(args[i], ' ');
		j = -1;
		while (str[++j])
		{
			num = my_atoi(str[j]);
			list = create_new_list(num);
			list_add_back(begin, list);
		}
		free_char_array(str);
	}
	if (is_there_dubles(*begin))
	{
		list_clear(begin);
		ft_exit();
	}
}
