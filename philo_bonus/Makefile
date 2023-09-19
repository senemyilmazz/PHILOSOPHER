SRCB =	main_bonus.c \
		child_utils_bonus.c \
		fill_struct_bonus.c \
		life_cycle_bonus.c \
		utils_bonus.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = philo_bonus

all : ${NAME}

${NAME}:
	@${CC} ${CFLAGS} ${SRCB} -o ${NAME}

fclean:
	@${RM} ${NAME}

re: fclean all

.PHONY: all fclean re