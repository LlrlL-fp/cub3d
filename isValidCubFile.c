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

bool	check_map(char *line, int fd)
{
	printf("line : %s\n", line);
	free(line);
	line = get_next_line(fd);
	if (line)
		printf("line2 : %s\n", line);
	free(line);
	return (true);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	is_texture(char *c)
{
	if (ft_strlen(c) == 2)
		return (ft_strncmp(c, "NO", 2) == 0 || ft_strncmp(c, "SO", 2) == 0
			|| ft_strncmp(c, "WE", 2) == 0 || ft_strncmp(c, "EA", 2) == 0);
	return (false);
}

bool	is_floor_or_ceiling(char *c)
{
	if (ft_strlen(c) == 1)
		return (*c == 'F' || *c == 'C');
	return (false);
}

int	get_size_null_term_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
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

bool	check_if_already_present(char c, bool *is_present, char *line, char *type)
{
	int		value;

	value = get_value_t_f_c(c);
	if (is_present[value])
		return (printf("error\n%s : %s %s already present\n",
				line, get_str_t_f_c(c), type), true);
	else
		is_present[value] = true;
	return (false);
}

bool	check_color_composition(char *color ,char *line)
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
			printf("error\n %s : Invalid color format, only digits and comma allowed\n", line);
			return (false);
		}
		i++;
	}
	if (nb_comma != 2)
	{
		{
			printf("error\n %s : Invalid color format, number of comma invalid\n", line);
			return (false);
		}
	}
	return (true);
}

bool check_num_valid(char **color_split, char *line)
{
	int	i;
	int	to_int;

	i = 0;

	while(color_split[i])
	{
		to_int = ft_atoi(color_split[i]);
		if(!(to_int >= 0 && to_int <= 255))
		{
			printf("error\n%s : Invalid color format, %s invalid number : must be between 0 and 255\n", line, color_split[i]);
			return (false);
		}	
		i++;
	}
	return (true);
}

bool handle_floor_ceiling(char *color, char *line)
{
	char	**color_split;
	int		len;
	int		size_split_color;

	len = ft_strlen(color);
	if (len < 5 || len > 11)
		return(printf("error\n %s : Invalid color format, length must be between 5 and 11\n", line), false);
	if (!check_color_composition(color, line))
		return (false);
	color_split = ft_split(color, ',');
	size_split_color = get_size_null_term_array(color_split);
	if (size_split_color != 3)
		return(printf("error\n %s : Invalid color format, must contain 3 number between 0 and 255 separated by comma\n", line), false);
	if (!check_num_valid(color_split, line))
		return (false);
	free_array(color_split);
	return (true);
}

bool handle_textures_f_c(bool *is_present, char **line_split, char *line)
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
	{
		printf("error\n%s : missing %s\n", line, info_type);
		return(false);
	}
	if (size_line_split > 2)
	{
		printf("error\n%s : Only 2 informations required : identifier and %s\n", line, info_type);
		if (value == F || value == C)
			printf("Color in format [0,255],[0,255],[0,255] (no space between ',')\n");
		return(false);
	}
	if ((value == F || value == C) && !is_already_present )
		return (handle_floor_ceiling(line_split[1], line));
	else
		return(!is_already_present);
}

bool	check_textures_and_f_c_and_map(int fd)
{
	char	*line;
	char	**line_split;
	bool	is_present[6];
	int		nb_l_valid;

	nb_l_valid = 0;
	init_bool_array(is_present, 6);
	line = get_next_line(fd);
	if (!line)
		return (write(2, "error\nempty file\n", 17), false);
	while (line && nb_l_valid != 6)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		line_split = ft_split(line, ' ');
		if (is_texture(line_split[0]) || is_floor_or_ceiling(line_split[0]))
		{
			nb_l_valid++;
			if (!handle_textures_f_c(is_present, line_split, line))
				return (false);
		}
		else if (line_split[0] && line_split[0][0] != '\n')
			return (printf("error\nInvalid identifier : %s\n", line_split[0]),
				false);
		free(line);
		free_array(line_split);
		line = get_next_line(fd);
	}
	if (line && nb_l_valid == 6)
		check_map(line, fd);
	else if (nb_l_valid != 6)
		return (write(2, "error\nNo all textures or floor color or ceiling color present\n", 62),
			false);
	else
		return (write(2, "error\nno map in file\n", 21), false);
	return (true);
}

bool	is_valid_cub_file(char *filename)
{
	int		fd;

	if (!is_valid_filename(filename))
	{
		write(2, "error\n.cub extension file name required\n", 40);
		return (false);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "error\nfile can't be opened\n", 27), false);
	if (!check_textures_and_f_c_and_map(fd))
		return (false);
	close(fd);
	return (true);
}


