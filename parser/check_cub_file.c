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
static bool	is_valid_filename(char *filename)
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

static bool	handle_textures_f_c(char **line_split, char *line,
		t_file_info *file_info)
{
	int		size_line_split;
	char	*info_type;
	bool	is_present;

	info_type = get_info_type(line_split[0][0]);
	is_present = is_already_present(line_split[0][0], file_info);
	if (is_present)
		return (error_parsing_double(line, get_str_t_f_c(line_split[0][0]),
			info_type, ALREADY_PRESENT_ERROR), false);
	size_line_split = get_size_null_term_array(line_split);
	if (size_line_split == 1)
		return (error_parsing_with_info_type(line, MISSING_INFO,
				info_type), false);
	if (size_line_split > 2)
	{
		error_parsing_extra_infos(line, EXTRA_INFOS,
			info_type, line_split[0][0]);
		return (false);
	}
	if ((line_split[0][0] == 'F' || line_split[0][0] == 'C') && ! is_present)
		return (check_floor_ceiling(line_split[1], line));
	else
		return (! is_present);
}

static bool	check_line(char *line, int *nb_l_valid, t_file_info *file_info)
{
	int		line_len;
	char	**line_split;
	bool	res;

	res = true;
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line[line_len - 1] = '\0';
	line_split = ft_split(line, ' ');
	if (is_texture(line_split[0]) || is_floor_or_ceiling(line_split[0]))
	{
		if (!handle_textures_f_c(line_split, line, file_info))
			res = false;
		if (res && ! set_info_in_file_info(file_info, line_split[0][0],
			ft_strdup(line_split[1]), line))
			res = false;
		(*nb_l_valid)++;
	}
	else if (line_split[0])
	{
		error_parsing_identifier(line, line_split[0]);
		res = false;
	}
	return (free_null_term_array(line_split), res);
}

static bool	check_textures_and_f_c_and_map(int fd, char *filename,
			t_file_info *file_info)
{
	char	*line;
	int		nb_l_valid;

	nb_l_valid = 0;
	line = get_next_line(fd);
	file_info->map_starting_pos++;
	file_info->filename = filename;
	if (!line)
		return (error_parsing(filename, EMPTY_FILE), false);
	while (line && nb_l_valid != 6)
	{
		file_info->map_starting_pos++;
		if (!check_line(line, &nb_l_valid, file_info))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	if (line && nb_l_valid == 6)
		return (check_map(line, fd, file_info));
	else if (nb_l_valid != 6)
		return (free(line), error_parsing(filename, MISSING_TEXTURE_OR_F_OR_C),
			false);
	else
		return (free(line), error_parsing(filename, MISSING_MAP), false);
	return (true);
}

t_file_info	check_cub_file(char *filename)
{
	int			fd;
	t_file_info	res;

	res = new_file_info();
	if (!is_valid_filename(filename))
	{
		error_parsing(filename, EXTENSION_ERROR);
		res.is_valid = false;
		return (res);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		error_parsing(filename, FILE_OPENING_ERROR);
		res.is_valid = false;
		return (res);
	}
	if (!check_textures_and_f_c_and_map(fd, filename, &res))
	{
		res.is_valid = false;
		return (close(fd), res);
	}
	close(fd);
	return (res);
}
