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

void	error_parsing(char *param, char *msg)
{
	printf("error\nParsing failed -> %s : %s\n", param, msg);
}

void	error_parsing_color(char *param, char *param2, char *msg)
{
	printf("error\nParsing failed : Invalid color format -> %s : %s -> %s\n", param, param2, msg);
}