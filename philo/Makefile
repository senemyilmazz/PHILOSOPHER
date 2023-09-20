SRCS = 	main.c \
		arg_check.c \
		fill_struct.c \
		kill_or_stop.c \
		life_cycle.c \
		eating_utils.c \
		utils.c

DIR = ./obj/
OBJ = ${addprefix ${DIR}, ${SRCS:.c=.o}}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = philo

all : ${NAME}
${NAME}: ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME} 

${DIR}%.o : %.c
	@mkdir -p ${DIR}
	@${CC} ${CFLAGS} -c $< -o $@

fclean:
	@${RM} ${NAME} ./obj

re: fclean all

.PHONY: all fclean re