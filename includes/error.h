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

#define EXTENSION_ERROR ".cub extension file name required."
#define FILE_OPENING_ERROR "File can't be opened."
#define COLOR_COM_NUM_ERROR "Only digits and commas are allowed"
#define COLOR_NB_COMMAS_ERROR "Must contain exactly 2 commas."
#define COLOR_LENGTH_ERROR "Length must be between 5 and 11."
#define COLOR_WRONG_NUMBER_ERROR "Invalid number : must be between 0 and 255."
#define COLOR_WRONG_COMMAS_ERROR "Wrong position of comma"

void	error_parsing(char *param, char *msg);
void	error_parsing_color(char *param, char *param2, char *msg);
