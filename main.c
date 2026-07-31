/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:24:00 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 13:24:03 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"
#include "includes/error.h"
#include "get_next_line/get_next_line.h"

void print_map(char **map, int size)
{
	int	i;

	if(!map)
		return;
	i = 0;
	while(i < size)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_file_info	file_info;
	char	**map;

	if (argc != 2)
		return (error_msg(WRONG_NB_ARGUMENT), 1);
	file_info = check_cub_file(argv[1]);
	map = get_map_from_file(file_info);
	printf("%d len and %d width\n", file_info.map_len, file_info.map_width);
	print_map(map, file_info.map_width);
	clean_file_info(&file_info);
	return (0);
}

