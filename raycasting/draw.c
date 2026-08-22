/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 00:15:08 by lren              #+#    #+#             */
/*   Updated: 2026/08/14 19:03:48 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_pixel(t_game *game, int x, int y, int color)
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

/*

void	draw_wall(t_game *game)
{
	int	y;

	game->ray.color = 0xFFFFFF;
	calculate_draw_start_end(game);
	y = game->ray.draw_start;
	while (y <= game->ray.draw_end)
	{
		draw_pixel(game, game->ray.x, y, game->ray.color);
		y++;
	}
}
*/

static t_texture	*get_wall_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x < 0)
			return (&game->we);
		else
			return (&game->ea);
	}
	else
	{
		if (game->ray.ray_dir_y < 0)
			return (&game->no);
		else
			return (&game->so);
	}
}

static int	get_texture_pixel(t_texture *texture, int x, int y)
{
	unsigned int	*pixel;

	if (!texture || !texture->addr || x < 0 || x >= texture->width
		|| y < 0 || y >= texture->height)
		return (0);
	pixel = (unsigned int *)(texture->addr
			+ y * texture->size_line
			+ x * (texture->bits_per_pixel / 8));
	return (*pixel);
}

static double	calculate_wall_x(t_game *game)
{
	double	wall_x;

	if (game->ray.side == 0)
		wall_x = game->player.pos_y + game->ray.perp_wall_dist
			* game->ray.ray_dir_y;
	else
		wall_x = game->player.pos_x + game->ray.perp_wall_dist
			* game->ray.ray_dir_x;
	wall_x = wall_x - (int)wall_x;
	if (wall_x < 0)
		wall_x += 1.0;
	return (wall_x);
}

static int	calculate_texture_x(t_game *game, t_texture *texture)
{
	double	wall_x;
	int		tex_x;

	wall_x = calculate_wall_x(game);
	tex_x = (int)(wall_x * texture->width);
	if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	return (tex_x);
}

static int	calculate_texture_y(t_game *game, t_texture *texture, int y)
{
	int	wall_top;
	int	tex_y;

	wall_top = WIN_HEIGHT / 2 - game->ray.line_height / 2;
	tex_y = (int)(((double)(y - wall_top) / game->ray.line_height)
		* texture->height);
	if (tex_y >= texture->height)
		tex_y = texture->height - 1;
	return (tex_y);
}

static void	draw_wall_column(t_game *game, t_texture *texture, int tex_x)
{
	int	y;
	int	tex_y;
	int	color;

	y = game->ray.draw_start;
	while (y <= game->ray.draw_end && y < WIN_HEIGHT)
	{
		tex_y = calculate_texture_y(game, texture, y);
		color = get_texture_pixel(texture, tex_x, tex_y);
		draw_pixel(game, game->ray.x, y, color);
		y++;
	}
}

void	draw_wall(t_game *game)
{
	t_texture	*texture;
	int			tex_x;

	calculate_draw_start_end(game);
	texture = get_wall_texture(game);
	if (!texture->addr || texture->width <= 0 || texture->height <= 0
		|| game->ray.line_height <= 0)
		return ;
	tex_x = calculate_texture_x(game, texture);
	draw_wall_column(game, texture, tex_x);
}
