/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:34:44 by malmany           #+#    #+#             */
/*   Updated: 2026/07/31 11:34:46 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"

static bool	is_zero_or_dir(char c)
{
	return (c == '0' || is_player_dir(c));
}

bool	is_space_accessible(char *prev_line, char *line, int line_num)
{
	int	i;
	int	size;

	i = 1;
	size = min(ft_strlen(prev_line), ft_strlen(line));
	while (i < size - 1)
	{
		if (prev_line[i] == ' ')
		{
			if (is_zero_or_dir(prev_line[i - 1])
				|| is_zero_or_dir(prev_line[i + 1]) || is_zero_or_dir(line[i]))
				return (error_parsing_map_space(MAP_SPACE_ACCESSIBLE,
						line_num - 1, i + 1), false);
		}
		else if (is_zero_or_dir(prev_line[i]))
		{
			if (line[i] == ' ')
				return (error_parsing_map_space(MAP_SPACE_ACCESSIBLE,
						line_num, i + 1), false);
		}
		i++;
	}
	return (true);
}
