CC			= gcc
FLAGS		= -Wall -Werror -Wextra -pthread

SRCS 		= srcs/

INCLUDES	= ${SRCS}includes/
SCRIPTS		= ${SRCS}scripts/

H			= ${INCLUDES}philo_one.h
C			= ${SCRIPTS}eat.c ${SCRIPTS}init.c ${SCRIPTS}main.c ${SCRIPTS}numbers.c ${SCRIPTS}print.c ${SCRIPTS}thread.c ${SCRIPTS}utils.c

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