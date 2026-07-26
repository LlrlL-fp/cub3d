/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:14:46 by lren              #+#    #+#             */
/*   Updated: 2026/07/26 20:17:54 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_game(t_game *game)
{
	if (!game)
		exit(EXIT_SUCCESS);
	if (game->frame_image && game->mlx)
		mlx_destroy_image(game->mlx, game->frame_image);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

//void mlx_destroy_display(void *mlx_ptr);
//int mlx_destroy_window(void *mlx_ptr, void *win_ptr);