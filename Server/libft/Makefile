NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FILES=ft_calloc.c ft_itoa.c ft_memset.c ft_putchar_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c
PRINTF=ft_printf.c hex.c hex_util.c printing.c
FILES_OBJ=$(FILES:%.c=%.o) $(PRINTF:%.c=ft_printf/%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ)

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
