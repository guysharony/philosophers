# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 15:15:26 by gsharony          #+#    #+#              #
#    Updated: 2020/10/07 15:15:28 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
FLAGS		= -Wall -Werror -Wextra -pthread

SRCS 		= srcs/

INCLUDES	= ${SRCS}includes/
SCRIPTS		= ${SRCS}scripts/

H			= ${INCLUDES}philo_two.h
C			= ${SCRIPTS}actions.c ${SCRIPTS}init.c ${SCRIPTS}main.c ${SCRIPTS}numbers.c ${SCRIPTS}print.c ${SCRIPTS}thread.c ${SCRIPTS}utils.c ${SCRIPTS}monitor.c

FILES		= ${U} ${C}

OBJS		= ${FILES:.c=.o}

EXE			= philo_two

all:		${EXE}

${EXE}:		${OBJS}
			${CC} ${FLAGS} -I ${H} -o ${EXE} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean