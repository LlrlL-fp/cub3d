/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:42:27 by lren              #+#    #+#             */
/*   Updated: 2026/07/26 20:18:16 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (exit_game(game));
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	game.mlx = NULL;
	game.win = NULL;
	game.frame_image = NULL;
	game.frame_addr = NULL;
	if (!init_mlx(&game) || !init_image(&game))
		exit_game(&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, EVENT_DESTROY, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
//t	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
//int	mlx_hook(void *win_ptr, 
//int event,int event_mask, int (*funct_ptr)(), void *param);
//int	mlx_loop(void *mlx_ptr);
