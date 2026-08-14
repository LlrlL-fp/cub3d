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
#include "cub3d.h"

#define WRONG_NB_ARGUMENT "Must have one argument : the *.cub file name"
#define EXTENSION_ERROR ".cub extension file name required."
#define FILE_OPENING_ERROR "File can't be opened."
#define COLOR_COM_NUM_ERROR "Only digits and commas are allowed"
#define COLOR_NB_COMMAS_ERROR "Must contain only 2 commas."
#define COLOR_LENGTH_ERROR "Length must be between 5 and 11."
#define COLOR_WRONG_NUMBER_ERROR "Invalid number : must be between 0 and 255."
#define COLOR_WRONG_NB_ARG_ERROR "Wrong number of arguments for color : \
3 needed in format [0-255],[0-255],[0-255]"
#define ALREADY_PRESENT_ERROR "already present."
#define MISSING_INFO "missing"
#define EXTRA_INFOS "Only 2 informations required : identifier and "
#define EMPTY_FILE "Empty file."
#define MISSING_MAP "Missing map."
#define MISSING_TEXTURE_OR_F_OR_C "Not all textures and/or \
ceiling color and/or floor color present."
#define MALLOC_FAILED "malloc failed."
#define WRONG_FIRST_LINE_MAP "can contain only ones and spaces."
#define WRONG_MIDDLE_LINE_MAP "can contain only ones ,zeros,  spaces and \
one character in {N, S, E, W}."
#define WRONG_MIDDLE_LINE_CLOSURE_MAP "must be closed by 1 \
(first and last character must be 1)."
#define MAP_MULTI_PLAYER "multi player detected"
#define WRONG_MAP_LEN "map length must be at least 3."
#define WRONG_MAP_WIDTH "map width must be at least 3."
#define NO_PLAYER_MAP "there is no player."
#define NL_IN_MAP_ERROR "New line not allowed in map."
#define MAP_ONE_LINE "contains only one line."
#define MAP_SPACE_ACCESSIBLE "a space is accessible!"

void	error_msg(char *msg);
void	error_parsing(char *param, char *msg);
void	error_parsing_double(char *line, char *param, char *param2, char *msg);
void	error_parsing_with_info_type(char *line, char *msg, char *info_type);
void	error_parsing_extra_infos(char *line, char *msg, char *info_type,
			char c);
void	error_parsing_color(char *line, char *param, char *msg);
void	error_parsing_identifier(char *line, char *param);
void	error_parsing_map(char *param, char *msg, int line_num);
void	error_parsing_map_multi_player(char *param, char *msg, int line_num,
			t_file_info *file_info);
void	error_parsing_map_size(char *msg);
void	error_parsing_map_nl(char *msg, int line_num);
void	error_parsing_map_space(char *msg, int line_num, int col_num);