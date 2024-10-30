NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address -g3
RM = rm -rf

SRC = main.c parser.c routines.c struct_utils.c threads.c actions.c mutex.c

OBJ_DIR = obj
OBJ	= $(addprefix ${OBJ_DIR}/, ${SRC:%.c=%.o})

all: $(NAME)

${NAME}: ${OBJ}
	@${MAKE} -C ./includes/Libft
	@${MAKE} -C ./includes/ft_printf
	@${CC} ${CFLAGS} ${OBJ} ./includes/Libft/libft.a ./includes/ft_printf/libftprintf.a ${xFLAGS} -o ${NAME}

${OBJ_DIR}/%.o:./%.c
	@mkdir -p ${OBJ_DIR}
	gcc ${CFLAGS} -c $< -o $@

clean:
	@${MAKE} -C ./includes/Libft fclean
	@${MAKE} -C ./includes/ft_printf fclean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

.PHONY: all clean fclean re debug