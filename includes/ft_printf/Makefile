NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = ft_printf.c ft_printf_utils.c \

OBJ_DIR = obj
OBJ	= $(addprefix ${OBJ_DIR}/, ${SRC:%.c=%.o})

all: $(NAME)

${NAME}: ${OBJ}
	ar -crs ${NAME} ${OBJ}

${OBJ_DIR}/%.o:./%.c
	@mkdir -p ${OBJ_DIR}
	gcc ${FLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all



.PHONY: all clean fclean re