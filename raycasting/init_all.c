/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:46:17 by lren              #+#    #+#             */
/*   Updated: 2026/08/15 15:27:33 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/error.h"

bool	init_game(t_game *game, char *filename)
{
	game->file = check_cub_file(filename);
	if (! game->file.is_valid)
		return (false);
	game->map = get_map_from_file(game->file);
	if (! game->map)
		return (false);
	game->mlx = NULL;
	game->win = NULL;
	game->frame_image = NULL;
	game->frame_addr = NULL;
	game->no.image = NULL;
	game->so.image = NULL;
	game->ea.image = NULL;
	game->we.image = NULL;
	game->ray = new_ray();
	game->player = game->file.player;
	return (true);
}

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_msg("mlx_init went wrong!"), false);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		return (error_msg("mlx_new_window went wrong!"), false);
	return (true);
}

bool	init_image(t_game *game)
{
	game->frame_image = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame_image)
		return (error_msg("mlx_new_image went wrong!"), false);
	game->frame_addr = mlx_get_data_addr(game->frame_image, &game->frame_bpp,
			&game->frame_size_line, &game->frame_endian);
	if (!game->frame_addr)
		return (error_msg("mlx_get_data_addr went wrong!"), false);
	return (true);
}

static bool	init_one_texture(t_game *game, t_texture *texture, char *path)
{
	if (!game || !game->mlx || !texture || !path)
		return (false);
	texture->image = mlx_xpm_file_to_image(game->mlx, path,
			&texture->width, &texture->height);
	if (!texture->image)
		return (false);
	texture->addr = mlx_get_data_addr(texture->image,
			&texture->bits_per_pixel,
			&texture->size_line,
			&texture->endian);
	if (!texture->addr)
		return (false);
	return (true);
}

bool	init_texture(t_game *game)
{
	if (!game)
		return (false);
	if (!init_one_texture(game, &game->no, game->file.north_path))
		return (error_init_textures("North", game->file.north_path), false);
	if (!init_one_texture(game, &game->so, game->file.south_path))
		return (error_init_textures("South", game->file.south_path), false);
	if (!init_one_texture(game, &game->we, game->file.west_path))
		return (error_init_textures("West", game->file.west_path), false);
	if (!init_one_texture(game, &game->ea, game->file.east_path))
		return (error_init_textures("East", game->file.east_path), false);
	return (true);
}
