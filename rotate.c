/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 13:15:21 by malmany           #+#    #+#             */
/*   Updated: 2026/08/11 13:15:24 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

/**
 * Pour faire tourner un vecteur (x, y) d'un angle a:
 * newx = x*cos(a)-y*sin(a)
 * newy = x*sin(a)+y*cos(a) 
 * 
 * ex : dir(0, -1) -> NORTH
 * et si on prend un angle de 90deg
 * cos(90deg)=0 et sin(90deg)=1
 * donc newx = 0*0-(-1)*1 = 1 et newy = 0*1+(-1)*0=0
 * ce qui donne (1, 0) -> EAST on est passe de nord a est donc rotation droite
 * et donc pour rotation gauche angle negatif
 * verif : cos(-90deg) = 0 et sin(-90) = -1
 *  * donc newx = 0*0-(-1)*-1 = -1 et newy = 0*-1+(-1)*0=0
 * ce qui donne (-1, 0) -> WEST on est passe de nord a ouest donc rotation gauche
 * 
 * donc angle positive pour rotation droite et
 *  angle negative pour rotation gauche
**/

static void	rotate_vector(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
}

/** 
 *  on plus de rotate dir il faut egalement rotate plane
 * qui est perpndiculaire a dir 
**/
void	rotate(t_game *game, double angle, char side)
{
	if (!game)
		return ;
	if (side == 'L')
	{
		if (angle > 0)
			angle = angle * -1;
	}
	if (side == 'R')
	{
		if (angle < 0)
			angle = angle * -1;
	}
	rotate_vector(&(game->player.dir_x), &(game->player.dir_y), angle);
	rotate_vector(&(game->player.plane_x), &(game->player.plane_y), angle);
}
