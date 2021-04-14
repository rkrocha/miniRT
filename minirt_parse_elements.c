/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:41:02 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/10 18:30:56 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** If a line that does not match any expected type identifier contains only
** white spaces, then it is ignored. If any other unexpected character is
** found, then both the line and the scene file are considered invalid.
*/
void	parse_invalid_element(char *line, bool *error, int line_num)
{
	if (!ft_strignore(line, WHITE_SPACES))
		return ;
	print_scene_error(SCENE_INVALID_TYPE, line_num);
	*error = true;
}

/*
** Multiple definitions of resolution, or resolution values smaller than 1
** will cause both the line and the scene file to be considered invalid.
*/
void	parse_resolution(char *line, t_scene *scene, bool *error, int line_num)
{
	if (scene->defined_resolution)
	{
		print_scene_error(SCENE_MULT_RES, line_num);
		*error = true;
		return ;
	}
	line++;
	line = ft_strignore(line, WHITE_SPACES);
	scene->render_width = ft_atoi(line);
	line = ft_strignore(line, DECIMAL_BASE);
	line = ft_strignore(line, WHITE_SPACES);
	scene->render_height = ft_atoi(line);
	scene->defined_resolution = true;
	if (scene->render_width <= 0 || scene->render_height <= 0)
	{
		print_scene_error(SCENE_RES, line_num);
		*error = true;
	}
}

void	parse_by_type(char *line, t_scene *scene, bool *scene_error)
{
	static int	line_num;

	line_num++;
	if (*line == '\0' || *line == '#')
		return ;
	else if (*line == 'R')
		parse_resolution(line, scene, scene_error, line_num);
	// else if (*line == 'A')
	// 	parse_amb_light(line, scene, scene_error, line_num);
	// else if (*line == 'c')
	// 	parse_camera(line, scene, scene_error, line_num);
	// else if (*line == 'l')
	// 	parse_light(line, scene, scene_error, line_num);
	// else if (*line == 'p' && *(line + 1) == 'l')
	// 	parse_plane(line, scene, scene_error, line_num);
	// else if (*line == 's' && *(line + 1) == 'p')
	// 	parse_sphere(line, scene, scene_error, line_num);
	// else if (*line == 's' && *(line + 1) == 'q')
	// 	parse_square(line, scene, scene_error, line_num);
	// else if (*line == 'c' && *(line + 1) == 'y')
	// 	parse_cylinder(line, scene, scene_error, line_num);
	// else if (*line == 't' && *(line + 1) == 'r')
	// 	parse_triangle(line, scene, scene_error, line_num);
	else
		parse_invalid_element(line, scene_error, line_num);
}