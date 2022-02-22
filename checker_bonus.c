/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcollen <wcollen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:55:14 by wcollen           #+#    #+#             */
/*   Updated: 2022/02/18 19:08:38 by wcollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_next_line(char **line)
{
	char	*buf;
	int		i;
	int		j;

	i = -1;
	buf = malloc(sizeof(char) * 4);
	if (!buf)
		return (0);
	j = read(0, &buf[++i], 1);
	while (j > 0 && buf[i] != '\0' && buf[i] != '\n')
		j = read(0, &buf[++i], 1);
	buf[i] = '\0';
	*line = buf;
	return (j);
}

void	free_and_exit(char *buf)
{
	free(buf);
	ft_exit();
}

void	make_operations(const char *buf, t_lst **a, t_lst **b)
{
	if (ft_strncmp(buf, "sa", 3) == 0)
		swap(a);
	else if (ft_strncmp(buf, "sb", 3) == 0)
		swap(b);
	else if (ft_strncmp(buf, "ss", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(buf, "pa", 3) == 0)
		push(b, a);
	else if (ft_strncmp(buf, "pb", 3) == 0)
		push(a, b);
	else if (ft_strncmp(buf, "ra", 3) == 0)
		rotate(a);
	else if (ft_strncmp(buf, "rb", 3) == 0)
		rotate(b);
	else if (ft_strncmp(buf, "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(buf, "rra", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(buf, "rrb", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(buf, "rrr", 4) == 0)
		rrr(a, b);
	else
		free_and_exit((char *)buf);
}

int	main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	char	*buf;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	parse_args(&argv[1], &a);
	while (get_next_line(&buf))
	{
		make_operations((const char *)buf, &a, &b);
		free(buf);
	}
	if (is_list_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	list_clear(&a);
}
