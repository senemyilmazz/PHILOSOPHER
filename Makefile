SRCS = 	./SRC/main.c \
		./SRC/utils.c \
		./SRC/fill_struct.c \
		./SRC/kill_all_func.c \
		./SRC/eating_utils.c \
		./SRC/meal_count.c \
		./SRC/time.c \
		./SRC/thread_loop.c 

SRCB =	./BONUS/main_bonus.c \
		./BONUS/eating_utils_bonus.c \
		./BONUS/fill_struct_bonus.c \
		./BONUS/terminator_bonus.c \
		./BONUS/life_cycle_bonus.c \
		./BONUS/time_bonus.c \
		./BONUS/utils_bonus.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
RM = rm -rf
NAMES = philo
NAMEB = philo_bonus

all : ${NAMES} ${NAMEB} 

${NAMES}: 
	@${CC} ${CFLAGS} ${SRCS} -o ${NAMES}

${NAMEB}:
	@${CC} ${CFLAGS} ${SRCB} -o ${NAMEB}

bonus : ${NAMEB}

clean:
	@${RM} ${NAMES} ${NAMEB}

fclean: clean
	@${RM} ${NAMES} ${NAMEB}

re: fclean all bonus

.PHONY: all clean fclean re bonus