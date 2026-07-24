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

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg(WRONG_NB_ARGUMENT), 1);
	is_valid_cub_file(argv[1]);
	return (0);
}
