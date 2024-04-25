# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 12:21:12 by gde-alme          #+#    #+#              #
#    Updated: 2022/05/24 14:48:00 by gde-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG	= push_swap

SRCS	= srcs/create_frame.c srcs/find_big_small.c \
		srcs/push.c srcs/main.c srcs/reset_frame.c \
		srcs/rmv_stack.c srcs/rotate_to_top.c \
		srcs/swap.c srcs/utils.c srcs/solve_5.c \
		srcs/rotate.c srcs/rev_rotate.c \
		srcs/push_swap_error.c srcs/move_chunk.c\
		srcs/fill_stack_a.c srcs/hanoi2.c
OBJS	= ${SRCS:.c=.o}
SRCS	+=	libftstk/add_to_stack.c  libftstk/ft_stacklen.c  libftstk/index.c libftstk/ft_split.c
MAIN	= srcs/main.c
HEADER	= -Iincludes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f
AR		= ar rc
RN		= ranlib


.c.o:		%.o : %.c
					${CC} ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}
			${CC} ${CFLAGS} ${OBJS} -o ${PROG}
${PROG}: ${OBJS}
			${AR} ${PROG} ${OBJS}
			${RN} ${PROG}
clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${PROG}

re: 		fclean all

.PHONY: all clean fclean re
