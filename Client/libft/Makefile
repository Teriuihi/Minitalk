NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FILES=ft_atoi ft_isdigit.c
FILES_OBJ=$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ)

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
