/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:46:31 by lren              #+#    #+#             */
/*   Updated: 2026/08/15 18:12:26 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render_frame(t_game *game)
{
	draw_background(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame_image, 0, 0);
	return (0);
}
/*int	mlx_put_image_to_window(void *mlx_ptr,void *win_ptr,
		void *img_ptr,int x, int y);
*/