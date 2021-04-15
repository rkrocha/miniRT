/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:09:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/14 21:22:40 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef MINIRT_DEBUG
#  define MINIRT_DEBUG 0
# endif

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_vectors.h"
# include "get_next_line.h"
# include "minirt_error.h"
# include "minirt_types.h"
# include "mlx.h"

/*
** minirt_scene.c:
*/
void	parse_scene(const char *file, t_scene *scene);
void	free_scene(t_scene *scene);

/*
** minirt_parse_elements.c:
*/
void	parse_by_type(char *line, t_scene *scene, bool *scene_error);

/*
** minirt_parse_objects.c:
*/


/*
** minirt_parse_utils.c:
*/
bool	get_next_float(float *number, char **line);
bool	get_next_int(int *number, char **line);

void	parse_invalid_element(char *line, bool *error, int line_num);
bool	parse_light_ratio(float *ratio, char **line, int line_num);
bool	parse_rgb(int *color, char **line, int line_num);
bool	parse_position(t_coord *position, char **line, int line_num);
bool	parse_orientation(t_coord *orient, char **line, int line_num);

/*
** minirt_debug_elements.c:
*/
void	debug_line(char *line, int line_num);
void	debug_res(char *line, t_scene scene, int line_num);
void	debug_ambl(char *line, t_light ambient, int line_num);
void	debug_camera(char *line, t_camera camera, int line_num);

#endif
