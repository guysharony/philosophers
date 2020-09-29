CC			= gcc
FLAGS		= -Wall -Werror -Wextra

SRCS 		= srcs/

INCLUDES	= ${SRCS}includes/
LIB			= ${SRCS}lib/
UTILS		= ${LIB}utils/

H			= ${INCLUDES}philosophers.h
U			= ${UTILS}ft_putchar.c ${UTILS}ft_putnbr.c ${UTILS}ft_putstr.c ${UTILS}ft_strcpy.c ${UTILS}ft_itoa.c ${UTILS}ft_time.c ${UTILS}ft_strlen.c ${UTILS}ft_nbrlen.c ${UTILS}ft_atoi.c ${UTILS}ft_isdigit.c ${UTILS}ft_number.c ${UTILS}ft_numbers.c
C			= ${LIB}init.c ${LIB}thread.c ${LIB}message.c ${LIB}action.c

FILES		= main.c ${U} ${C}

OBJS		= ${FILES:.c=.o}

EXE			= philo_three

all:		${EXE}

${EXE}:		${OBJS}
			${CC} ${FLAGS} -I ${H} -o ${EXE} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean