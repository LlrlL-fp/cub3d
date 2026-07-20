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

/*  
	- doit contenir 4 lignes correspondant aux textures 
	  et 1 ligne pour le Floor et 1 ligne pour Ceiling color
	, dans n'importe quel ordre
	, peuvent contenir des espaces
	, peuvent etre separes par des lignes

	Pour les textures en ignorant les espaces :
	 - doit commencer par NO/N ou SO/S ou WE/W ou EA/E 
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
		- donc peut contenir que 0 ,1 ,espace (espace, tab, ...) 
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

bool	is_valid_cub_file(char *filename)
{
	if (!is_valid_filename(filename))
	{
		write(2, "error\nThe file name must be with the .cub extension\n", 52);
		return (false);
	}
	//autre verif a faire (textures, floor, ceiling and map)
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("must have 1 argument\n"), 1);
	is_valid_cub_file(argv[1]);
	return (0);
}
