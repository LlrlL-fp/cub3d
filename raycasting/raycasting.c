/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:54:24 by lren              #+#    #+#             */
/*   Updated: 2026/08/05 20:14:20 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	perform_dda(t_game *game)
{
	int		hit;
	int		map_x;
	int		map_y;

	hit = 0;
	map_x = (int)game->player.pos_x;
	map_y = (int)game->player.pos_y;
	while (hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map[map_y][map_x] == '1')
			hit = 1;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	double	camera_x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		game->ray.x = x;
		camera_x = calculate_camera_x(x);
		calculate_ray_dir(game, camera_x);
		calculate_delta_dist(game);
		calculate_step_sidedist_x(game);
		calculate_step_sidedist_y(game);
		perform_dda(game);
		x++;
	}
}
//side = 0 : le rayon touche un côté vertical (axe x).
//side = 1 : le rayon touche un côté horizontal (axe y)

/*
                    Camera Plane
      ●────●────●────●────●────●
       \    \    |    /    /    /
        \    \   |   /    /    /
                 Player (P)

Screen :
| 0 | 1 | 2 | 3 | 4 | 5 |



Sample a point on the camera plane
        ↓
Cast a ray from the player
        ↓
Trace the ray
        ↓
Hit the first wall
        ↓
Calculate the distance
   ↓
Render the wall column

                  Ray
                   \
                    \
+-----+-----+-----+-----+
|     |     |     |     |
+-----+-----+-----+-----+
|  P  |\    |     | ███ |
+-----+-\---+-----+-----+
|     |  \  |     |     |
+-----+-----+-----+-----+
*/