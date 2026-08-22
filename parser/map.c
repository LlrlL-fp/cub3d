/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:07:09 by malmany           #+#    #+#             */
/*   Updated: 2026/07/31 13:07:12 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../get_next_line/get_next_line.h"
#include "../includes/error.h"

static char	*read_map_start(int fd, int starting_pos)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 1;
	while (i < starting_pos)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		i++;
	}
	return (line);
}

static void	fill_map_row_with_space(char *row, int map_len, int line_len)
{
	int	i;

	i = line_len;
	while (i < map_len)
	{
		row[i] = ' ';
		i++;
	}
	row[i] = '\0';
}

static char	**read_map_rows(t_file_info file_info, int fd, char **map)
{
	char	*line;
	int		i;
	int		line_len;

	i = 0;
	line = read_map_start(fd, file_info.map_starting_pos);
	while (i < file_info.map_width && line)
	{
		map[i] = malloc(file_info.map_len + 1);
		if (!map[i])
			return (free_map(i, map), free(line), close(fd),
				error_msg(MALLOC_FAILED), NULL);
		line_len = get_line_len_without_nl(line);
		ft_strlcpy(map[i], line, line_len + 1);
		if (line_len < file_info.map_len)
			fill_map_row_with_space(map[i], file_info.map_len, line_len);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (i < file_info.map_width)
		return (close(fd), free(line), free_map(i, map),
			error_msg(MALLOC_FAILED), NULL);
	return (close(fd), free(line), map);
}

char	**get_map_from_file(t_file_info file_info)
{
	char	**map;
	int		fd;

	fd = open(file_info.filename, O_RDONLY);
	if (fd < 0)
		return (error_parsing(file_info.filename, FILE_OPENING_ERROR), NULL);
	map = malloc(file_info.map_width * sizeof(char *));
	if (!map)
		return (close(fd), error_msg(MALLOC_FAILED), NULL);
	return (read_map_rows(file_info, fd, map));
}

void	free_map(int size, char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
