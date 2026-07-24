/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:53:50 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 15:53:53 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/cub3d.h"
#include "../includes/error.h"

bool	is_floor_or_ceiling(char *c)
{
	if (ft_strlen(c) == 1)
		return (*c == 'F' || *c == 'C');
	return (false);
}

static bool	check_color_composition(char *color ,char *line)
{
	int i;
	int nb_comma;

	i = 0;
	nb_comma = 0;
	while (color[i])
	{
		if(color[i] == ',')
			nb_comma++;
		else if(!ft_isdigit(color[i]) && color[i] != ',')
		{
			error_parsing_color(line, color, COLOR_COM_NUM_ERROR);
			return (false);
		}
		i++;
	}
	if (nb_comma != 2)
	{
		{
			error_parsing_color(line, color, COLOR_NB_COMMAS_ERROR);
			return (false);
		}
	}
	return (true);
}

static bool check_num_valid(char **color_split, char *line)
{
	int	i;
	int	to_int;

	i = 0;

	while (color_split[i])
	{
		to_int = ft_atoi(color_split[i]);
		if (!(to_int >= 0 && to_int <= 255))
		{
			error_parsing_color(line, color_split[i], COLOR_WRONG_NUMBER_ERROR);
			return (false);
		}	
		i++;
	}
	return (true);
}

bool check_floor_ceiling(char *color, char *line)
{
	char	**color_split;
	int		len;
	int		size_split_color;

	len = ft_strlen(color);
	if (len < 5 || len > 11)
		return (error_parsing_color(line, color, COLOR_LENGTH_ERROR), false);
	if (!check_color_composition(color, line))
		return (false);
	color_split = ft_split(color, ',');
	size_split_color = get_size_null_term_array(color_split);
	if (size_split_color != 3)
		return (error_parsing_color(line, color, COLOR_WRONG_COMMAS_ERROR), false);
	if (!check_num_valid(color_split, line))
		return (false);
	free_null_term_array(color_split);
	return (true);
}