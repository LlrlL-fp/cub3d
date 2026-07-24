/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:45:15 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 15:45:18 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_value_t_f_c(char c)
{
	if (c == 'N')
		return (NO);
	else if (c == 'S')
		return (SO);
	else if (c == 'W')
		return (WE);
	else if (c == 'E')
		return (EA);
	else if (c == 'F')
		return (F);
	else if (c == 'C')
		return (C);
	return (-1);
}

char	*get_str_t_f_c(char c)
{
	if (c == 'N')
		return ("North");
	else if (c == 'S')
		return ("South");
	else if (c == 'W')
		return ("West");
	else if (c == 'E')
		return ("East");
	else if (c == 'F')
		return ("Floor");
	else if (c == 'C')
		return ("Ceiling");
	return ("Error");
}

char	*get_info_type(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return ("path");
	else if (c == 'F' || c == 'C')
		return ("color");
	return ("error");
}

char	*get_type(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return ("texture");
	else if (c == 'F' || c == 'C')
		return ("color");
	return ("error");
}