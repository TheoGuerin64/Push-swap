# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguerin <tguerin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 17:44:14 by tguerin           #+#    #+#              #
#    Updated: 2022/11/11 19:43:37 by tguerin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		main.c \
			commands1.c \
			commands2.c \
			commands3.c \
			utils.c \
			utils2.c \
			parse.c \
			sort.c \
			sort2.c \
			sort3.c
SRCS_B =	checker.c \
			parse.c \
			commands1.c \
			commands2.c \
			commands3.c \
			utils2.c \
			utils.c
FT_SRC =	libft
SRCS_GNL =	get_next_line/get_next_line.c

OBJS =		${SRCS:.c=.o}
OBJS_B =	${SRCS_B:.c=.o}
OBJ_GNL =	${SRCS_GNL:.c=.o}

NAME =		push_swap
NAME_B =	checker

CC =		clang
RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror
FTFLAGS =	-lft -L${FT_SRC}

.c.o:
			${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${FT_SRC}
			${CC} -o ${NAME} ${OBJS} ${FTFLAGS}

${NAME_B}:	${OBJ_GNL} ${OBJS_B}
			make -C ${FT_SRC}
			${CC} -o ${NAME_B} ${OBJ_GNL} ${OBJS_B} ${FTFLAGS}

clean:
			${RM} ${OBJS} ${OBJS_B} ${OBJ_GNL}

fclean:		clean
			${RM} ${NAME} ${NAME_B}

re:			fclean all

all:		${NAME}

bonus:		${NAME_B}

.PHONY: clean, fclean, re, all, bonus
