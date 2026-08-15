NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -std=gnu99 -Iminilibx-linux/minilibx-linux

SRC = parser/check_cub_file.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
	  main.c error.c utils_null_term_array.c parser/check_map.c parser/parsing_utils.c          \
	  parser/check_floor_ceiling.c parser/parsing_error.c parser/parsing_error2.c               \
	  parser/parsing_utils2.c parser/file_info.c parser/player.c parser/parsing_map_error.c      \
	  parser/parsing_map_utils.c parser/check_map_utils.c parser/map.c parser/color_to_rgb.c     \
	  raycasting/draw.c \
	  raycasting/event.c \
	  raycasting/init_all.c \
	  raycasting/ray.c \
	  raycasting/raycasting_calculate.c \
	  raycasting/raycasting.c \
	  raycasting/render.c \
	  cleanup.c move.c rotate.c \

INCLUDE = libft/libft.h includes/cub3d.h includes/error.h

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# $(MLX_LIB):
#	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) \
		$(LIBFT_LIB) $(MLX_LIB) -lXext -lX11 -lm -lz

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re