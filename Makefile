CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC =  push_swap.c
OBJ = $(SRC:.c=.o)

%.o: %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	make -C $(PRINTF_DIR)
	cp $(PRINTF) $(NAME)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
