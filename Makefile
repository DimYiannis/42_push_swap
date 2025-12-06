CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC =  push_swap.c actions.c helpers.c main.c utils.c sorting.c cost.c logic.c target.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
