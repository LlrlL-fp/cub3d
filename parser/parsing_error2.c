/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:38:14 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 18:38:17 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"

void	error_parsing_color(char *line, char *param, char *msg)
{
	printf("error\nParsing failed : Invalid color format -> %s : %s -> %s\n",
		line, param, msg);
}

void	error_parsing_identifier(char *line, char *param)
{
	printf("error\nParsing failed : %s : %s Invalid identifier.\n",
		line, param);
}
