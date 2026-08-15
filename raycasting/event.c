/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 17:42:27 by lren              #+#    #+#             */
/*   Updated: 2026/08/15 18:51:35 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	events_init(t_game *game)
{
	if (!game)
		return ;
	mlx_hook(game->win, KeyPress, KeyPressMask,
		(int (*)())key_handler, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask,
		(int (*)())exit_game, game);
	mlx_loop_hook(game->mlx, (int (*)())render_frame, game);
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
		rotate(game, ROT_ANGLE_RADIAN, 'L');
	else if (keycode == KEY_RIGHT)
		rotate(game, ROT_ANGLE_RADIAN, 'R');
	return (0);
}


//t	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
//int	mlx_hook(void *win_ptr, 
//int event,int event_mask, int (*funct_ptr)(), void *param);
//int	mlx_loop(void *mlx_ptr);
