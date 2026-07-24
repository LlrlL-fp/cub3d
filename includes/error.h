/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmany <malmany@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:45:21 by malmany           #+#    #+#             */
/*   Updated: 2026/07/24 13:45:24 by malmany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WRONG_NB_ARGUMENT "Must have one argument : the *.cub file name"
#define EXTENSION_ERROR ".cub extension file name required."
#define FILE_OPENING_ERROR "File can't be opened."
#define COLOR_COM_NUM_ERROR "Only digits and commas are allowed"
#define COLOR_NB_COMMAS_ERROR "Must contain exactly 2 commas."
#define COLOR_LENGTH_ERROR "Length must be between 5 and 11."
#define COLOR_WRONG_NUMBER_ERROR "Invalid number : must be between 0 and 255."
#define COLOR_WRONG_COMMAS_ERROR "Wrong position of comma"
#define ALREADY_PRESENT_ERROR "already present."
#define MISSING_INFO "missing"
#define EXTRA_INFOS "Only 2 informations required : identifier and "
#define EMPTY_FILE "Empty file."
#define MISSING_MAP "Missing map."
#define MISSING_TEXTURE_OR_F_OR_C "Not all textures and/or \
ceiling color and/or floor color present."

void	error_msg(char *msg);
void	error_parsing(char *param, char *msg);
void	error_parsing_double(char *line, char *param, char *param2, char *msg);
void	error_parsing_with_info_type(char *line, char *msg, char *info_type);
void	error_parsing_extra_infos(char *line, char *msg, char *info_type,
			int value);
void	error_parsing_color(char *line, char *param, char *msg);
void	error_parsing_identifier(char *line, char *param);
