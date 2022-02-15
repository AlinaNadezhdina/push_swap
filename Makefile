# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcollen <wcollen@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 16:39:36 by wcollen           #+#    #+#              #
#    Updated: 2022/02/14 15:55:55 by wcollen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	push_swap

NAME_B		=	checker

SRCS		=	push_swap.c\
				lists.c\
				parse_arguments.c\
				check_list_elements.c\
				shacker_sort_arr.c\
				push_operations.c\
				swap_operations.c\
				rotate_operations.c \
				reverse_rotate_operations.c\
				conditional_sort_3_elem.c\
				assign_min_cost.c\
				utils.c\
				final_sort.c

SRCS_B		=	checker_bonus.c\
				lists_bonus.c\
				parse_arguments_bonus.c\
				check_list_elements_bonus.c\
				stack_operations1_bonus.c\
				stack_operations2_bonus.c\

CFLAGS		= 	-Wall -Werror -Wextra -g

HEADER		=	push_swap.h

HEADER_B	=	push_swap_bonus.h

OBJS		=	$(SRCS:.c=.o)

OBJS_B		=	$(SRCS_B:.c=.o)

CC			=	gcc

LIBFTDIR	= 	./libft

.PHONY 		: all clean fclean re re_libft bonus

all 		: $(NAME)

bonus		: $(NAME_B)

$(NAME) 	:  $(OBJS) $(HEADER)
	@make -C $(LIBFTDIR)
	$(CC) -L./libft -lft $(CFLAGS) $(SRCS) -o $(NAME)

$(NAME_B)	: $(OBJS_B) $(HEADER_B)
	@make -C $(LIBFTDIR)
	$(CC) -L./libft -lft $(CFLAGS) $(SRCS_B) -o $(NAME_B)

%.o 		: %.c $(HEADER) $(HEADER_B)
	$(CC) $(CFLAGS) -c $< -o $@

clean 		:
	@rm -f $(OBJS)
	@rm -f $(OBJS_B)
	@make clean -C $(LIBFTDIR)
#
fclean 		: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@make fclean -C $(LIBFTDIR)
#
re_libft 	:
	@make re -C $(LIBFTDIR)
#
re 			: fclean re_libft all

