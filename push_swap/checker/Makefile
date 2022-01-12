# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 13:06:51 by mapontil          #+#    #+#              #
#    Updated: 2022/01/10 14:43:00 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			error.c \
			init.c \
			do_op.c \
			list_op.c \
			utils.c \
			get_next_line.c \
			get_next_line_utils.c

OBJS	=	$(addprefix srcs/, $(SRCS:.c=.o))
HEAD	=	includes/checker.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	checker

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