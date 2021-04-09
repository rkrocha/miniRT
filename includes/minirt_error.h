/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:56:53 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/09 18:45:04 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

# define SYSTEM_GNL			"in get_next_line() function"
# define SYSTEM_MALLOC		"in malloc() function"
# define SYSTEM_OPEN		"in open() function"

# define SCENE_EXT			"Scene file must use extension .rt"

# define SCENE_RES			"invalid resolution"
# define SCENE_MULT_RES		"additional resolution setting"

# define SCENE_MULT_AMB		"additional ambient lighting"
# define SCENE_LIGHT		"invalid lighting ratio"
# define SCENE_RGB			"invalid rgb color"
# define SCENE_CAM_FOV		"invalid camera FOV"

# define SCENE_ELEM_TYPE	"invalid element type"
# define SCENE_ELEM_COORD	"invalid coordinates"
# define SCENE_ELEM_ORIENT	"invalid orientation vector"
# define SCENE_ELEM_DIM		"invalid object dimension"

# define SCENE_WARN_DARK	"Low ambient lighting ratio! Scene may be too dark"
# define SCENE_WARN_NOCAM	"Scene contains no camera! Rendering black screen"

/*
** minirt_error.c:
*/
void	*malloc_check(size_t size);
void	print_scene_error(const char *message, const char *file, size_t line);
void	print_system_error(const char *message);

#endif
