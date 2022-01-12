# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/24 09:53:56 by mapontil          #+#    #+#              #
#    Updated: 2022/01/10 13:12:12 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			error.c \
			init.c	\
			sort.c \
			sort_big.c \
			list_op.c \
			utils.c

OBJS	=	$(addprefix srcs/, $(SRCS:.c=.o))
HEAD	=	includes/push_swap.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap

%.o:		%.c $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
all:		$(NAME)
clean:
			rm -f $(OBJS)
fclean:		clean
			rm -f $(NAME)
re:			fclean all
.PHONY:		all clean fclean re