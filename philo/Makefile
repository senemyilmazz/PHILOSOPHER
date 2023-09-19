SRCS = 	main.c \
		error_check.c \
		fill_struct.c \
		kill_or_stop.c \
		life_cycle.c \
		eating_utils.c \
		utils.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = philo

all : ${NAME}

${NAME}:
	@${CC} ${CFLAGS} ${SRCS} -o ${NAME}

fclean:
	@${RM} ${NAME}

re: fclean all

.PHONY: all fclean re