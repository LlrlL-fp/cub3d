/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:24:00 by malmany           #+#    #+#             */
/*   Updated: 2026/08/15 19:52:51 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/error.h"
#include "get_next_line/get_next_line.h"
#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (error_msg(WRONG_NB_ARGUMENT), 1);
	if (! init_game(&game, argv[1]))
		return (clean_file_info(&(game.file)), 1);
	if (! init_mlx(&game) || ! init_image(&game))
		exit_game(&game);
	if (!init_texture(&game))
		exit_game(&game);
	render_frame(&game);
	events_init(&game);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}
