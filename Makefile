NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = parser/check_cub_file.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
	  main.c error.c utils_null_term_array.c parser/check_map.c parser/parsing_utils.c          \
	  parser/check_floor_ceiling.c

INCLUDE = libft/libft.h includes/cub3d.h includes/error.h 

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)
	$(MAKE) -C $(LIBFT_DIR) clean

re: fclean all

.PHONY: all clean fclean re