/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lren <lren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:20:13 by lren              #+#    #+#             */
/*   Updated: 2026/08/01 18:38:19 by lren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	color_to_rgb(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	if (!rgb)
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_null_term_array(rgb);
	return (create_rgb(r, g, b));
}

//┌────────┬────────┬────────┬────────┐
//│ 000000 │   Red  │ Green  │  Blue  │
//└────────┴────────┴────────┴────────┘