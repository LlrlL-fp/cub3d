/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 13:18:08 by malmany           #+#    #+#             */
/*   Updated: 2026/08/01 17:29:14 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"

t_file_info	new_file_info(void)
{
	t_file_info	res;

	res.is_valid = true;
	res.player = new_player();
	res.north_path = NULL;
	res.south_path = NULL;
	res.west_path = NULL;
	res.east_path = NULL;
	res.ceiling_rgb = 0;
	res.floor_rgb = 0;
	res.map_starting_pos = 0;
	res.map_len = -1;
	res.map_width = 0;
	return (res);
}

bool	set_info_in_file_info(t_file_info *f_inf, char type_info,
			char *info, char *line)
{
	if (!info)
		return (error_parsing(line, MALLOC_FAILED), false);
	if (type_info == 'N')
		f_inf->north_path = info;
	else if (type_info == 'S')
		f_inf->south_path = info;
	else if (type_info == 'W')
		f_inf->west_path = info;
	else if (type_info == 'E')
		f_inf->east_path = info;
	else if (type_info == 'F')
		f_inf->floor_rgb = color_to_rgb(info);
	else if (type_info == 'C')
		f_inf->ceiling_rgb = color_to_rgb(info);
	return (true);
}

void	set_map_len_with(t_file_info *file_info, int len)
{
	file_info->map_len = max(file_info->map_len, len);
	(file_info->map_width)++;
}

void	clean_file_info(t_file_info *f_inf)
{
	if (!f_inf)
		return ;
	free(f_inf->north_path);
	free(f_inf->south_path);
	free(f_inf->west_path);
	free(f_inf->east_path);
}
