NAME=client
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

FILES=main.c
FILES_BONUS=main_bonus.c

ifdef BONUS
	FILES_OBJ=$(FILES_BONUS:%.c=%.o)
else
	FILES_OBJ=$(FILES:%.c=%.o)
endif

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(FILES_OBJ) libft/libft.a

clean:
	$(RM) $(FILES_OBJ)
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean $(NAME)

.PHONY: make all clean fclean re
