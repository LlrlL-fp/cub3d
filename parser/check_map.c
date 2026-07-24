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

bool	check_map(char *line, int fd)
{
	printf("line : %s\n", line);
	free(line);
	line = get_next_line(fd);
	if (line)
		printf("line2 : %s\n", line);
	free(line);
	return (true);
}

bool	exist_char(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	if (!game || !game->map)
		return (false);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			c = game->map[y][x];
			if (c != '0' && c != '1' && c != 'N' && c != 'S'
				&& c != 'E' && c != 'W' && c != ' ')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
// Vérifie que la carte contient uniquement : 0, 1, N, S, E, W et les espaces.

void	count_player(t_game *game, int y, int x)
{
	char	c;

	c = game->map[y][x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		game->player_count++;
		game->player_x = x;
		game->player_y = y;
		game->player_dir = c;
	}
}