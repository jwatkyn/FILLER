NAME: players/jwatkyn.filler

SRCS: srcs/main.c \
	srcs/parcing.c \
	srcs/update.c

FLAGS: -Wall -Wextra -Werror -I./includes

OBJ: ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a
	@echo "Filler done"

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
