/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:23:30 by malmany           #+#    #+#             */
/*   Updated: 2026/07/30 00:28:57 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 500

# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100

# define KEY_LEFT   65361 // rotate left
# define KEY_RIGHT  65363 // rotate right

# define KEY_ESC    65307

# define EVENT_DESTROY 17

//y = ligne, x = colonne
typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	dir;
}	t_player;

typedef struct s_file_info
{
	bool		is_valid;
	char		*filename;
	t_player	player;
	char		*north_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	char		*floor_color;
	char		*ceiling_color;
	int			map_starting_pos;
	int			map_len;
	int			map_width;
}	t_file_info;

typedef struct s_texture
{
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*frame_image;
	char		*frame_addr;
	int			frame_bpp;
	int			frame_size_line;
	int			frame_endian;
	t_file_info	file;
	char		**map;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
}	t_game;

//player
t_player	new_player(void);
void		set_player(t_file_info *file_info, char dir,
				int pos_x, int pos_y);

// file info
t_file_info	new_file_info(void);
void		clean_file_info(t_file_info *f_inf);
bool		set_info_in_file_info(t_file_info *f_inf,
				char type_info, char *info, char *line);
void		set_map_len_with(t_file_info *file_info, int len);

t_file_info	check_cub_file(char *filename);

//parsing utils
char		*get_str_t_f_c(char c);
char		*get_info_type(char c);
char		*get_type(char c);
bool		is_texture(char *c);
bool		is_already_present(char c, t_file_info *file_info);
bool		is_player_dir(char c);
bool		is_valid_map_car(char c);
int			max(int a, int b);
int			get_line_len_without_nl(char *line);

//check floor_ceiling
bool		is_floor_or_ceiling(char *c);
bool		check_floor_ceiling(char *color, char *line);

//check map
bool		check_map(char *line, int fd, t_file_info *file_info);

//utils null terminating array
int			get_size_null_term_array(char **array);
void		free_null_term_array(char **array);

//init all
bool		init_mlx(t_game *game);
bool		init_image(t_game *game);
bool		init_one_texture(t_game *game, t_texture *texture, char *path);
bool		init_texture(t_game *game);

// draw
void		draw_pixel(t_game *game, int x, int y, int color);

//cleanup
void		destroy_texture(t_game *game);
int			exit_game(t_game *game);


//event
int			key_handler(int keycode, t_game *game);
void		move_forward(t_game *game);
void		move_backward(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		rotate_left(t_game *game);
void		rotate_right(t_game *game);
int			key_handler(int keycode, t_game *game);









#endif