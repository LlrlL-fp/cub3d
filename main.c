/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:24:00 by malmany           #+#    #+#             */
/*   Updated: 2026/08/02 19:19:12 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/error.h"
#include "get_next_line/get_next_line.h"
#include "includes/cub3d.h"

void	print_map(char **map, int size)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < size)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_file_info	file_info;
	char		**map;

	if (argc != 2)
		return (error_msg(WRONG_NB_ARGUMENT), 1);
	file_info = check_cub_file(argv[1]);
	map = get_map_from_file(file_info);
	printf("%d len and %d width\n", file_info.map_len, file_info.map_width);
	print_map(map, file_info.map_width);
	clean_file_info(&file_info);
	printf("valu rot in radins %f\n", ROT_ANGLE_RADIAN);
	return (0);
}

/*int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	(void)argv;
	game.mlx = NULL;
	game.win = NULL;
	game.frame_image = NULL;
	game.frame_addr = NULL;
	game.ray = new_ray();
	if (!init_mlx(&game) || !init_image(&game))
		exit_game(&game);
	render_frame(&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, EVENT_DESTROY, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}*/
