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



void	set_player(t_file_info *file_info, char dir, int pos_x, int pos_y)
{
	file_info->player.dir = dir;
	file_info->player.pos_x = pos_x;
	file_info->player.pos_y = pos_y;
	if (dir == 'N')
	{
		file_info->player.dir_x = 0;
		file_info->player.dir_y = -1;
		file_info->player.plane_x = 0.66;
		file_info->player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		file_info->player.dir_x = 0;
		file_info->player.dir_y = 1;
		file_info->player.plane_x = 0.66;
		file_info->player.plane_y = 0;
	}
	else if (dir == 'O')
	{
		file_info->player.dir_x = -1;
		file_info->player.dir_y = 0;
		file_info->player.plane_x = 0.66;
		file_info->player.plane_y = 0;
	}
	else if (dir == 'E')
	{
		file_info->player.dir_x = 1;
		file_info->player.dir_y = 0;
		file_info->player.plane_x = 0.66;
		file_info->player.plane_y = 0;
	}
}
