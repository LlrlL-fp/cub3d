/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:06:22 by malmany           #+#    #+#             */
/*   Updated: 2026/08/11 12:06:25 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_player_pos(t_game *game, double new_posx, double new_posy)
{
	if (game->map[(int)new_posy][(int)new_posx] != '1')
	{
		game->player.pos_x = new_posx;
		game->player.pos_y = new_posy;
	}
}

// avancer dans dir
void	move_forward(t_game *game)
{
	double	new_posx;
	double	new_posy;

	if (! game)
		return ;
	new_posx = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_posy = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	set_player_pos(game, new_posx, new_posy);
}

// reculer dans dir
void	move_backward(t_game *game)
{
	double	new_posx;
	double	new_posy;

	if (!game)
		return ;
	new_posx = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_posy = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	set_player_pos(game, new_posx, new_posy);
}

/** 
 *  pour aller a gauche ou droite, faut un vecteur perpendiculaire a dir
 * deux vecteurs perpendiculaires si produit scalaire null
 * produit scalaire A . B = AxBx + AyBy
 * (dirx, diry), pour gauche : (diry,-dirx) et pour droite : (-diry, dirx)
 * car ex pour (1, 0) -> (0, -1) est a gauch et (0, 1) est a droite
**/

void	move_left(t_game *game)
{
	double	new_posx;
	double	new_posy;

	if (!game)
		return ;
	new_posx = game->player.pos_x + game->player.dir_y * MOVE_SPEED;
	new_posy = game->player.pos_y - game->player.dir_x * MOVE_SPEED;
	set_player_pos(game, new_posx, new_posy);
}

void	move_right(t_game *game)
{
	double	new_posx;
	double	new_posy;

	if (!game)
		return ;
	new_posx = game->player.pos_x - game->player.dir_y * MOVE_SPEED;
	new_posy = game->player.pos_y + game->player.dir_x * MOVE_SPEED;
	set_player_pos(game, new_posx, new_posy);
}
