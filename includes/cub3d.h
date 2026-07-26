/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:23:30 by malmany           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/20 18:23:32 by malmany          ###   ########.fr       */
=======
/*   Updated: 2026/07/26 20:09:21 by lren             ###   ########.fr       */
>>>>>>> 3e4f2b1 (raycasting init)
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
<<<<<<< HEAD
# define C 5   

typedef struct s_file_info
{
	bool	is_valid;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor_color;
	char	*ceiling_color;
	int		map_staarting_pos;
	int		map_len;
	int		map_witdh;
}	t_file_info;

=======
# define C 5

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

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;

}	t_player;

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
>>>>>>> 3e4f2b1 (raycasting init)
typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*frame_image;
	char		*frame_addr;
	int			frame_bpp;
	int			frame_size_line;
	int			frame_endian;

	char		**map;
	t_player	player;
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
}	t_game;

<<<<<<< HEAD
bool	is_valid_cub_file(char *filename);

//parsing utils
int		get_value_t_f_c(char c);
char	*get_str_t_f_c(char c);
char	*get_info_type(char c);
char	*get_type(char c);
bool	is_texture(char *c);

//check floor_ceiling
bool	is_floor_or_ceiling(char *c);
bool	check_floor_ceiling(char *color, char *line);

//check map
bool	check_map(char *line, int fd);

//utils null terminating array
int		get_size_null_term_array(char **array);
void	free_null_term_array(char **array);

//cleanup
void    free_line(char *line);
void    free_line_and_array(char *line, char **array);

#endif
=======
//init_all
bool	init_mlx(t_game *game);
//event
int		key_handler(int keycode, t_game *game);
//cleanup
int		exit_game(t_game *game);


#endif

>>>>>>> 3e4f2b1 (raycasting init)
