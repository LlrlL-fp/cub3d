/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 00:15:08 by lren              #+#    #+#             */
/*   Updated: 2026/08/06 17:21:34 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixel(t_game *game, int x, int y, int color)
{
	unsigned int	*pixel;

	if (!game || !game->frame_addr)
		return ;
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	pixel = (unsigned int *)(game->frame_addr
			+ y * game->frame_size_line
			+ x * (game->frame_bpp / 8));
	*pixel = color;
}

void	draw_background(t_game *game)
{
	int	y;
	int	x;

	if (!game || !game->frame_addr)
		return ;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				draw_pixel(game, x, y, game->file.ceiling_rgb);
			else
				draw_pixel(game, x, y, game->file.floor_rgb);
			x++;
		}
		y++;
	}
}

static void	calculate_draw_start_end(t_game *game)
{
	game->ray.draw_start = -game->ray.line_height / 2 + WIN_HEIGHT / 2;
	game->ray.draw_end = game->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	if (game->ray.draw_end >= WIN_HEIGHT)
		game->ray.draw_end = WIN_HEIGHT - 1;
}

void	draw_wall(t_game *game)
{
	int	y;

	calculate_draw_start_end(game);
	y = game->ray.draw_start;
	while (y <= game->ray.draw_end)
	{
		draw_pixel(game, game->ray.x, y, game->ray.color);
		y++;
	}
}
