/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:37:34 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 13:37:35 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/cub3d.h"

void	error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
}

void	error_init_textures(char *texture, char *texture_path)
{
	printf("Error\n%s texture file : %s can't be loaded!\n",
		texture, texture_path);
}
