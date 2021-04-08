/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:56:53 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/08 09:13:50 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ERROR_H
# define MINIRT_ERROR_H

# define SYSTEM_GNL			"get_next_line() function"
# define SYSTEM_MALLOC		"malloc() function"
# define SYSTEM_OPEN		"open() function"

# define SCENE_EXT			"Scene file must use extension .rt"

# define SCENE_RES			"invalid resolution"
# define SCENE_MULT_RES		"additional resolution setting"

# define SCENE_MUL_AMB		"additional ambient lighting"
# define SCENE_LIGHT		"invalid lighting ratio"
# define SCENE_RGB			"invalid rgb color"
# define SCENE_CAM_FOV		"invalid FOV setting"

# define SCENE_ELEM_ID		"invalid element identifier"
# define SCENE_ELEM_COORD	"invalid coordinates"
# define SCENE_ELEM_ORIENT	"invalid orientation vector"
# define SCENE_ELEM_DIM		"invalid dimension"

# define SCENE_WARN_DARK	"Scene contains ambient light of ratio zero"
# define SCENE_WARN_NOCAM	"Scene contains no camera"

/*
** minirt_error.c:
*/
void	*malloc_check(size_t size);
void	print_scene_error(const char *message, const char *file, size_t line);
void	print_system_error(const char *message);

#endif
