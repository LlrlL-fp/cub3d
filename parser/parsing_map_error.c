/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:32:42 by malmany           #+#    #+#             */
/*   Updated: 2026/07/28 11:32:43 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

void	error_parsing_map(char *param, char *msg, int line_num)
{
	printf("Error\nParsing failed, Wrong map, line \
%d in map -> %s : %s\n", line_num, param, msg);
}

void	error_parsing_map_multi_player(char *param, char *msg,
		int line_num, t_file_info *file_info)
{
	printf("Error\nParsing failed, Wrong map, line \
%d in map -> %s : %s, A player was already present in line %d col %d\n",
		line_num, param, msg, (int)file_info->player.pos_y + 1,
		(int)file_info->player.pos_x + 1);
}

void	error_parsing_map_size(char *msg)
{
	printf("Error\nParsing failed, Wrong map : %s\n", msg);
}

void	error_parsing_map_nl(char *msg, int line_num)
{
	printf("Error\nParsing failed, Wrong map -> line %d in map : %s\n",
		line_num, msg);
}

void	error_parsing_map_space(char *msg, int line_num, int col_num)
{
	printf("Error\nParsing failed, Wrong map -> line %d, col %d in map : %s\n",
		line_num, col_num, msg);
}
