/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calculate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:38:31 by lren              #+#    #+#             */
/*   Updated: 2026/08/05 17:22:29 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	calculate_camera_x(int x)
{
	return ((2.0 * x / WIN_WIDTH) - 1.0);
}

void	calculate_ray_dir(t_game *game, double camera_x)
{
	game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
}

void	calculate_delta_dist(t_game *game)
{
	if (game->ray.ray_dir_x == 0)
		game->ray.delta_dist_x = 1e30;
	else
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	if (game->ray.ray_dir_y == 0)
		game->ray.delta_dist_y = 1e30;
	else
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
}

void	calculate_step_sidedist_x(t_game *game)
{
	int		map_x;

	map_x = (int)game->player.pos_x;
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.pos_x - map_x)
			* game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (map_x + 1.0 - game->player.pos_x)
			* game->ray.delta_dist_x;
	}
}

void	calculate_step_sidedist_y(t_game *game)
{
	int		map_y;

	map_y = (int)game->player.pos_y;
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.pos_y - map_y)
			* game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (map_y + 1.0 - game->player.pos_y)
			* game->ray.delta_dist_y;
	}
}

/*fabs() : prendre la valeur absolue d’un nombre flottant 
		(supprimer le signe négatif). = rendre un nombre positif;
	ex: fabs(-5.5) = 5.5
	1e30 = 1 × 10³⁰ 
*/

/*calculate_camera_x()
↓
calculate_ray_dir()
↓
calculate_delta_dist()
↓
calculate_side_dist()
↓
perform_dda()
↓
calculate_perp_distance()
↓
calculate_wall_height()

          y+
          ↑
          |
          |
x- <------P------> x+
          |
          |
          ↓
          y-
fabs() = floating-point absolute value
*/