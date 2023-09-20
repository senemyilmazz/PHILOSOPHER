SRCB =	main_bonus.c \
		child_utils_bonus.c \
		fill_struct_bonus.c \
		life_cycle_bonus.c \
		arg_check_bonus.c

DIR = ./obj/
OBJB = ${addprefix ${DIR}, ${SRCB:.c=.o}}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = philo_bonus

all : ${NAME}

${NAME}: ${OBJB}
	@${CC} ${CFLAGS} ${OBJB} -o ${NAME}

${DIR}%.o : %.c
	@mkdir -p ${DIR}
	@${CC} ${CFLAGS} -c $< -o $@

fclean:
	@${RM} ${NAME} ${DIR}

re: fclean all

.PHONY: all fclean re