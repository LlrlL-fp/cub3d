/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:38:14 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 18:38:17 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

void	error_parsing(char *param, char *msg)
{
	printf("error\nParsing failed -> %s : %s\n", param, msg);
}

void	error_parsing_double(char *line, char *param, char *param2, char *msg)
{
	printf("error\nParsing failed -> %s : %s %s %s\n", line,
		param, param2, msg);
}

void	error_parsing_with_info_type(char *line, char *msg, char *info_type)
{
	printf("error\nParsing failed -> %s : %s %s\n", line, msg, info_type);
}

void	error_parsing_extra_infos(char *line, char *msg,
			char *info_type, int value)
{
	error_parsing_with_info_type(line, msg, info_type);
	if (value == F || value == C)
		printf("               -> Color expected in format [0,255],[0,255],\
[0,255] (no space between ',')\n");
}
