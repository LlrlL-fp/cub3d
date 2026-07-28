/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 10:19:59 by malmany           #+#    #+#             */
/*   Updated: 2026/07/28 10:20:02 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

t_player	new_player(void)
{
	t_player	res;

	res.pos_x = -1;
	res.pos_y = -1;
	res.dir = '\0';
	return (res);
}

void	set_player(t_file_info *file_info, char dir, int pos_x, int pos_y)
{
	file_info->player.dir = dir;
	file_info->player.pos_x = pos_x;
	file_info->player.pos_y = pos_y;
}
