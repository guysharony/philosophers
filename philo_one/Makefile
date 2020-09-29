CC			= gcc
FLAGS		= -Werror -Wextra -Wall -pthread

SRCS 		= srcs/

INCLUDES	= ${SRCS}includes/
SCRIPTS		= ${SRCS}scripts/

H			= ${INCLUDES}philo_one.h
C			= ${SCRIPTS}actions.c ${SCRIPTS}init.c ${SCRIPTS}main.c ${SCRIPTS}numbers.c ${SCRIPTS}print.c ${SCRIPTS}thread.c ${SCRIPTS}time.c

FILES		= ${U} ${C}

OBJS		= ${FILES:.c=.o}

EXE			= philo_one

all:		${EXE}

${EXE}:		${OBJS}
			${CC} ${FLAGS} -I ${H} -o ${EXE} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean
