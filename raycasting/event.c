/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:42:27 by lren              #+#    #+#             */
/*   Updated: 2026/08/01 19:13:19 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (exit_game(game));
	return (0);
}

void	move_forward(t_game *game)
{
	if (!game)
		return ;
}

void	move_backward(t_game *game)
{
	if (!game)
		return ;
}

void	move_left(t_game *game)
{
	if (!game)
		return ;
}

void	move_right(t_game *game)
{
	if (!game)
		return ;
}

void	rotate_left(t_game *game)
{
	if (!game)
		return ;
}

void	rotate_right(t_game *game)
{
	if (!game)
		return ;
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (exit_game(game));
	else if (keycode == KEY_W)
		move_forward(game);
	else if (keycode == KEY_S)
		move_backward(game);
	else if (keycode == KEY_A)
		move_left(game);
	else if (keycode == KEY_D)
		move_right(game);
	else if (keycode == KEY_LEFT)
		rotate_left(game);
	else if (keycode == KEY_RIGHT)
		rotate_right(game);
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
	render_frame(&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, EVENT_DESTROY, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
//t	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
//int	mlx_hook(void *win_ptr, 
//int event,int event_mask, int (*funct_ptr)(), void *param);
//int	mlx_loop(void *mlx_ptr);
