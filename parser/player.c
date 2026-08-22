/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:19:59 by malmany           #+#    #+#             */
/*   Updated: 2026/08/15 19:59:50 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_player	new_player(void)
{
	t_player	res;

	res.pos_x = -1;
	res.pos_y = -1;
	res.dir = '\0';
	res.dir_x = 0;
	res.dir_y = 0;
	res.plane_x = 0;
	res.plane_y = 0;
	return (res);
}

static void	set_player_dir(t_player *player, double dir_x, double dir_y)
{
	player->dir_x = dir_x;
	player->dir_y = dir_y;
}

/**
 * 		  N
       -1 ↑
          |
          |
O <------P------> E
 -1       |     1
          |
          ↓ 1
          S 
 **/

/* plane_x and plane_y are used to calculate the camera plane, 
which is perpendicular to the direction vector (dir_x, dir_y). 
plane_x = -dir_y * plane_length and plane_y = dir_x * plane_length.
*/
void	set_player(t_file_info *file_info, char dir, int pos_x, int pos_y)
{
	double	plane_len;

	plane_len = 0.66;
	file_info->player.dir = dir;
	file_info->player.pos_x = (double)pos_x + 0.5;
	file_info->player.pos_y = (double)pos_y + 0.5;
	if (dir == 'N')
		set_player_dir(&(file_info->player), 0, -1);
	else if (dir == 'S')
		set_player_dir(&(file_info->player), 0, 1);
	else if (dir == 'O')
		set_player_dir(&(file_info->player), -1, 0);
	else if (dir == 'E')
		set_player_dir(&(file_info->player), 1, 0);
	file_info->player.plane_x = -file_info->player.dir_y * plane_len;
	file_info->player.plane_y = file_info->player.dir_x * plane_len;
}
