# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 14:45:48 by svanmeen          #+#    #+#              #
#    Updated: 2023/09/05 17:33:07 by svanmeen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c	ft_time.c	filldata.c	bornphilo.c	prompt.c death.c action.c special.c
HSRC	=	philo.h
OBJS	=	${SRCS:.c=.o}

NAME	= philo

GCC		= cc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror

%.o: %.c	${HSRC}
			${GCC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS} ${HSRC}
			${GCC} -pthread -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
