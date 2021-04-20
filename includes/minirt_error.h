/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:56:53 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/20 11:51:01 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

/*
** SYSTEM ERROR MESSAGES:
*/
# define SYSTEM_GNL			"in get_next_line() function"
# define SYSTEM_MALLOC		"in malloc() function"
# define SYSTEM_OPEN		"in open() function"

/*
** SCENE ERROR MESSAGES:
*/
# define SCENE_EXT			"Scene file must use extension .rt"

# define SCENE_FEW_ARGS		"insufficient arguments"

# define SCENE_NO_RES		"Resolution undefined"
# define SCENE_MULT_RES		"additional resolution setting"
# define SCENE_RES			"invalid resolution"

# define SCENE_NO_AMBL		"Ambient lighting undefined"
# define SCENE_MULT_AMBL	"additional ambient lighting"
# define SCENE_LIGHT		"invalid lighting ratio"
# define SCENE_RGB			"invalid RGB sequence"
# define SCENE_CAM_FOV		"invalid camera FOV"

# define SCENE_COORD		"invalid coordinates"
# define SCENE_ORIENT		"invalid orientation vector"
# define SCENE_DIMENSION	"invalid object dimension"

# define SCENE_INVALID_TYPE	"invalid element type"

/*
** SCENE WARNING MESSAGES:
*/
# define SCENE_WARN_DARK	"Low ambient lighting ratio! Scene may be too dark"
# define SCENE_WARN_NO_CAM	"Scene contains no camera! Rendering black screen"
# define SCENE_WARN_NO_OBJ	"Scene contains no objects! What a sad sight..."

/*
** DEBUG MESSAGES:
*/
# define DEBUG_MODE			"\n\033[1;33mMINIRT_DEBUG ON\033[0m\n"

/*
** minirt_error.c:
*/
void	*malloc_check(size_t size);
void	print_minirt_usage(void);
void	print_warning(char *message);
void	print_scene_error(const char *message, size_t line);
void	print_system_error(const char *message);

#endif
