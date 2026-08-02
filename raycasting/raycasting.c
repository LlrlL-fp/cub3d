/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:54:24 by lren              #+#    #+#             */
/*   Updated: 2026/08/02 19:49:29 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"







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