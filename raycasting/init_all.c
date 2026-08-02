/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:46:17 by lren              #+#    #+#             */
/*   Updated: 2026/08/02 19:13:26 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!game->win)
		return (false);
	return (true);
}

bool	init_image(t_game *game)
{
	game->frame_image = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame_image)
		return (false);
	game->frame_addr = mlx_get_data_addr(game->frame_image, &game->frame_bpp,
			&game->frame_size_line, &game->frame_endian);
	if (!game->frame_addr)
		return (false);
	return (true);
}

bool	init_one_texture(t_game *game, t_texture *texture, char *path)
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
		return (false);
	if (!init_one_texture(game, &game->so, game->file.south_path))
		return (false);
	if (!init_one_texture(game, &game->we, game->file.west_path))
		return (false);
	if (!init_one_texture(game, &game->ea, game->file.east_path))
		return (false);
	return (true);
}



/*bool	init_player(t_game *game, int x, int y, char dir)
{
	if (!game || !ft_strchr("NSEW", dir))
		return (false);
	game->player.x = x;
	game->player.y = y;
	game->player.dir = dir;
	return (true);
}

bool	init_texture()
/*

//void	*mlx_init(void);
//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

//void	*mlx_new_image(void *mlx_ptr, int width, int height);
//char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
 int *size_line,int *endian)

/*1。init_mlx()

2。 init_image()

3。 init_player()

4。init_texture()
*/
