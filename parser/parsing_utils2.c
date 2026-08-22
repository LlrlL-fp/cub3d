/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:45:15 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 15:45:18 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"

bool	is_texture(char *c)
{
	if (ft_strlen(c) == 2)
		return (ft_strncmp(c, "NO", 2) == 0 || ft_strncmp(c, "SO", 2) == 0
			|| ft_strncmp(c, "WE", 2) == 0 || ft_strncmp(c, "EA", 2) == 0);
	return (false);
}

bool	is_already_present(char c, t_file_info *file_info)
{
	if (c == 'N')
		return (!(file_info->north_path == NULL));
	else if (c == 'S')
		return (!(file_info->south_path == NULL));
	else if (c == 'E')
		return (!(file_info->east_path == NULL));
	else if (c == 'W')
		return (!(file_info->west_path == NULL));
	else if (c == 'F')
		return (!(file_info->floor_rgb == 0));
	else if (c == 'C')
		return (!(file_info->ceiling_rgb == 0));
	return (false);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}
