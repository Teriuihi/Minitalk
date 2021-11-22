NAME=server
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

FILES=main.c
FILES_BONUS=main_bonus.c
FILES_BONUS_OBJ=$(FILES_BONUS:%.c=%.o)
FILES_OBJ=$(FILES:%.c=%.o)

ifdef BONUS
	ALL_FILES_OBJ=$(FILES_BONUS)
else
	ALL_FILES_OBJ=$(FILES)
endif

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(MAKE) -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(FILES_OBJ) libft/libft.a

bonus:
	$(MAKE) BONUS=1 all

clean:
	$(RM) $(FILES_OBJ) $(FILES_BONUS_OBJ)
	$(MAKE) -C libft/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean $(NAME)

.PHONY: make all clean fclean re
