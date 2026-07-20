NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = parser/isValidCubFile.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)
	$(MAKE) -C $(LIBFT_DIR) clean

re: fclean all

.PHONY: all clean fclean re