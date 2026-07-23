/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 18:23:30 by malmany           #+#    #+#             */
/*   Updated: 2026/07/23 23:16:18 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_game
{
	char	**map;
	int		player_count;
	int		player_x;
	int		player_y;
	char	player_dir;
}	t_game;

#endif