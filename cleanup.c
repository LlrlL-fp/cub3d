/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:31:20 by malmany           #+#    #+#             */
/*   Updated: 2026/07/30 00:02:09 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	destroy_texture(t_game *game)
{
	if (!game)
		return ;
	if (game->no.image)
		mlx_destroy_image(game->mlx, game->no.image);
	if (game->so.image)
		mlx_destroy_image(game->mlx, game->so.image);
	if (game->ea.image)
		mlx_destroy_image(game->mlx, game->ea.image);
	if (game->we.image)
		mlx_destroy_image(game->mlx, game->we.image);
}

int	exit_game(t_game *game)
{
	clean_file_info(&(game->file));
	free_map(game->file.map_width, game->map);
	destroy_texture(game);
	if (game->frame_image)
		mlx_destroy_image(game->mlx, game->frame_image);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_SUCCESS);
}

//void mlx_destroy_display(void *mlx_ptr);
//int mlx_destroy_window(void *mlx_ptr, void *win_ptr);