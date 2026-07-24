/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidCubFile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:55:59 by malmany           #+#    #+#             */
/*   Updated: 2026/07/20 17:56:01 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../get_next_line/get_next_line.h"
#include "../includes/error.h"
/*  
	- doit contenir 4 lignes correspondant aux textures 
	  et 1 ligne pour le Floor et 1 ligne pour Ceiling color
	, dans n'importe quel ordre
	, peuvent contenir des espaces
	, peuvent etre separes par des lignes

	Pour les textures en ignorant les espaces :
	 - doit commencer par NO ou SO ou WE ou EA
	 -(en ignorant les espaces)suivi du path 
	 ( donc verifier si la ligne contient exactement 2 mots)
	 - on doit verifier que notre fichier contient 
	 	bien une ligne pour chacun des textures (pas une texture oublie 
		ou qu'il y ait deux fois  meme texture)				
	 
	Pour Floor color en ignorant les espaces :
	 - doit commencer par F
	 -(en ignorant les espaces)suivi de 3 nombres entre 0 et 255,
	  separes par des virgules

	Pour Ceiling color pareil mais doit commemcer par C.

	- suivi du map :
		- premiere et derniere ligne compose que de 1
		- toutes les lignes doivent commencer et terminer par 1
		- peut contenir des espaces
		- donc peut contenir que 0 ,1 ,espace
		  et N ou S ou E ou W(position et direction du joueur) 
*/

// verifie si le nom du fichier termine par .cub
bool	is_valid_filename(char *filename)
{
	int	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (filename[len - 1] != 'b' || filename[len - 2] != 'u'
		|| filename[len - 3] != 'c' || filename[len - 4] != '.')
		return (false);
	return (true);
}

void	init_bool_array(bool *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = false;
		i++;
	}
}

bool	check_if_already_present(char c, bool *is_present, char *line,
		char *type)
{
	int		value;

	value = get_value_t_f_c(c);
	if (is_present[value])
		return (error_parsing_double(line, get_str_t_f_c(c),
				type, ALREADY_PRESENT_ERROR), true);
	else
		is_present[value] = true;
	return (false);
}

bool	handle_textures_f_c(bool *is_present, char **line_split, char *line)
{
	int		size_line_split;
	char	*info_type;
	int		value;
	bool	is_already_present;

	is_already_present = check_if_already_present(line_split[0][0],
			is_present, line, get_type(line_split[0][0]));
	if (is_already_present)
		return (false);
	info_type = get_info_type(line_split[0][0]);
	value = get_value_t_f_c(line_split[0][0]);
	size_line_split = get_size_null_term_array(line_split);
	if (size_line_split == 1)
		return (error_parsing_with_info_type(line, MISSING_INFO,
				info_type), false);
	if (size_line_split > 2)
	{
		error_parsing_extra_infos(line, EXTRA_INFOS, info_type, value);
		return (false);
	}
	if ((value == F || value == C) && ! is_already_present)
		return (check_floor_ceiling(line_split[1], line));
	else
		return (! is_already_present);
}

/*bool	check_line(char *line)
{
	int		line_len;
	char	**line_split;

	line_len = ft_strlen(line);
}*/

bool	check_textures_and_f_c_and_map(int fd, char *filename)
{
	char	*line;
	char	**line_split;
	bool	is_present[6];
	int		nb_l_valid;

	nb_l_valid = 0;
	init_bool_array(is_present, 6);
	line = get_next_line(fd);
	if (!line)
		return (error_parsing(filename, EMPTY_FILE), false);
	while (line && nb_l_valid != 6)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		line_split = ft_split(line, ' ');
		if (is_texture(line_split[0]) || is_floor_or_ceiling(line_split[0]))
		{
			nb_l_valid++;
			if (!handle_textures_f_c(is_present, line_split, line))
				return (free_line_and_array(line, line_split), false);
		}
		else if (line_split[0] && line_split[0][0] != '\n')
			return (error_parsing_identifier(line, line_split[0]),free_line_and_array(line, line_split),
				false);
		free_line_and_array(line, line_split);
		line = get_next_line(fd);
	}
	if (line && nb_l_valid == 6)
		return (check_map(line, fd));
	else if (nb_l_valid != 6)
		return (free_line(line), error_parsing(filename, MISSING_TEXTURE_OR_F_OR_C),
			false);
	else
		return (free_line(line), error_parsing(filename, MISSING_MAP), false);
	return (true);
}

bool	is_valid_cub_file(char *filename)
{
	int		fd;

	if (!is_valid_filename(filename))
	{
		error_parsing(filename, EXTENSION_ERROR);
		return (false);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_parsing(filename, FILE_OPENING_ERROR);
		return (false);
	}
	if (!check_textures_and_f_c_and_map(fd, filename))
		return (close(fd), false);
	close(fd);
	return (true);
}
