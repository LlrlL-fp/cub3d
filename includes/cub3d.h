/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:23:30 by malmany           #+#    #+#             */
/*   Updated: 2026/07/20 18:23:32 by malmany          ###   ########.fr       */
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

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 4
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

typedef struct s_game
{
	char	**map;
	int		player_count;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_game;

bool	is_valid_cub_file(char *filename);

//parsing utils
int		get_value_t_f_c(char c);
char	*get_str_t_f_c(char c);
char	*get_info_type(char c);
char	*get_type(char c);

//check floor_ceiling

bool	is_floor_or_ceiling(char *c);
bool	check_floor_ceiling(char *color, char *line);

//check map
bool	check_map(char *line, int fd);

//utils null terminating array
int		get_size_null_term_array(char **array);
void	free_null_term_array(char **array);

#endif