/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:06:29 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 15:06:31 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../get_next_line/get_next_line.h"
#include "../includes/error.h"

static bool	check_first_last_line(char *line, t_file_info *file_info)
{
	int		i;
	int		len;

	i = 0;
	len = get_line_len_without_nl(line);
	while (i < len)
	{
		if (line[i] != '1' && line[i] != ' ')
			return (error_parsing_map(line, WRONG_FIRST_LINE_MAP,
					(file_info->map_width) + 1), false);
		i++;
	}
	file_info->map_len = max(file_info->map_len, len);
	return (true);
}

static bool	is_valid_middle_line(char *line, t_file_info *file_info)
{
	int		i;
	int		len;

	if (line[0] == '\n')
		return (error_parsing_map_nl(NL_IN_MAP_ERROR,
				(file_info->map_width) + 1), false);
	i = 0;
	len = get_line_len_without_nl(line);
	if (line[0] != '1' || line[len - 1] != '1')
		return (error_parsing_map(line, WRONG_MIDDLE_LINE_CLOSURE_MAP,
				(file_info->map_width) + 1), false);
	while (++i < len)
	{
		if (!is_valid_map_car(line[i]))
			return (error_parsing_map(line, WRONG_MIDDLE_LINE_MAP,
					(file_info->map_width) + 1), false);
		if (is_player_dir(line[i]))
		{
			if (file_info->player.dir)
				return (error_parsing_map_multi_player(line, MAP_MULTI_PLAYER,
						(file_info->map_width) + 1, file_info), false);
			set_player(file_info, line[i], i + 1, (file_info->map_width) + 1);
		}
	}
	return (set_map_len_with(file_info, len), true);
}

static bool	check_map_width_len_player(int len, int width, char player_dir)
{
	bool	res;

	res = true;
	if (len < 3)
	{
		error_parsing_map_size(WRONG_MAP_LEN);
		res = false;
	}
	if (width < 3)
	{
		error_parsing_map_size(WRONG_MAP_WIDTH);
		res = false;
	}
	if (!player_dir)
	{
		error_parsing_map_size(NO_PLAYER_MAP);
		res = false;
	}
	return (res);
}

static bool	get_and_check_first_line(char *line, int fd, t_file_info *file_info,
		char **prev_line)
{
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
		(file_info->map_starting_pos)++;
	}
	if (line)
	{
		if (!check_first_last_line(line, file_info))
			return (free(line), false);
		file_info->map_width++;
		*prev_line = ft_strdup(line);
		if (! *prev_line)
			return (error_parsing(line, MALLOC_FAILED), free(line), false);
		free(line);
		return (true);
	}
	else
		return (error_parsing(file_info->filename, MISSING_MAP), false);
}

bool	check_map(char *line, int fd, t_file_info *file_info)
{
	char	*prev_line;

	prev_line = NULL;
	if (!get_and_check_first_line(line, fd, file_info, &prev_line))
		return (false);
	line = get_next_line(fd);
	if (!line)
		return (free(prev_line), error_parsing_map_size(MAP_ONE_LINE), false);
	while (line)
	{
		if (!is_valid_middle_line(line, file_info)
			|| !is_space_accessible(prev_line, line, file_info->map_width))
			return (free(prev_line), free(line), false);
		free(prev_line);
		prev_line = ft_strdup(line);
		if (! prev_line)
			return (error_parsing(line, MALLOC_FAILED), free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_first_last_line(prev_line, file_info))
		return (free(line), free(prev_line), false);
	return (free(line), free(prev_line),
		check_map_width_len_player(file_info->map_len, file_info->map_width,
			file_info->player.dir));
}
