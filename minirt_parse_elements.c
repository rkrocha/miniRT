/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:41:02 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/15 10:52:46 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Multiple definitions of resolution, or resolution values smaller than 1
** will cause both the line and the scene file to be considered invalid.
*/
static void	parse_res(char *line, t_scene *scene, bool *error, int line_num)
{
	char	*original_line;

	original_line = line;
	if (scene->defined_resolution)
	{
		print_scene_error(SCENE_MULT_RES, line_num);
		*error = true;
		return ;
	}
	get_next_int(&scene->render_width, &line);
	get_next_int(&scene->render_height, &line);
	scene->defined_resolution = true;
	if (scene->render_width <= 0 || scene->render_height <= 0)
	{
		print_scene_error(SCENE_RES, line_num);
		*error = true;
	}
	if (MINIRT_DEBUG)
		debug_res(original_line, *scene, line_num);
}

static void	parse_ambl(char *line, t_scene *scene, bool *error, int line_num)
{
	char	*original_line;

	original_line = line;
	if (scene->defined_ambient_light)
	{
		print_scene_error(SCENE_MULT_AMBL, line_num);
		*error = true;
		return ;
	}
	if (!parse_light_ratio(&scene->ambient.ratio, &line, line_num))
		*error = true;
	if (!parse_rgb(&scene->ambient.color, &line, line_num))
		*error = true;
	scene->defined_ambient_light = true;
	if (MINIRT_DEBUG)
		debug_ambl(original_line, scene->ambient, line_num);
}

static void	parse_camera(char *line, t_list **camera, bool *error, int line_num)
{
	t_camera	*new_cam;
	char		*original_line;

	original_line = line;
	new_cam = (t_camera *)malloc_check(sizeof(t_camera));
	ft_bzero(new_cam, sizeof(new_cam));
	if (!parse_position(&new_cam->position, &line, line_num)
		|| !(parse_orientation(&new_cam->orient, &line, line_num)))
		*error = true;								// normalize orientation
	if (!get_next_float(&new_cam->fov, &line)
		|| new_cam->fov <= 0.0 || new_cam->fov > 180.0)// check zero condition
	{
		print_scene_error(SCENE_CAM_FOV, line_num);
		*error = true;
	}
	if (!(*camera))
		*camera = ft_lstnew(new_cam);
	else
		ft_lstadd_back(camera, ft_lstnew(new_cam));
	if (MINIRT_DEBUG)
		debug_camera(original_line, *new_cam, line_num);
}

static void	parse_light(char *line, t_list **light, bool *error, int line_num)
{
	t_light	*new_light;
	char	*original_line;

	original_line = line;
	new_light = (t_light *)malloc_check(sizeof(t_light));
	ft_bzero(new_light, (sizeof(new_light)));
	if (!parse_position(&new_light->position, &line, line_num)
		|| !parse_light_ratio(&new_light->ratio, &line, line_num)
		|| !parse_rgb(&new_light->color, &line, line_num))
		*error = true;
	if (!(*light))
		*light = ft_lstnew(new_light);
	else
		ft_lstadd_back(light, ft_lstnew(new_light));
	if (MINIRT_DEBUG)
		debug_light(original_line, *new_light, line_num);
}

void	parse_by_type(char *line, t_scene *scene, bool *scene_error)
{
	static int	line_num;

	line_num++;
	if (*line == '\0' || *line == '#')
		return ;
	else if (*line == 'R')
		parse_res(line, scene, scene_error, line_num);
	else if (*line == 'A')
		parse_ambl(line, scene, scene_error, line_num);
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
	else if (*line == 'c')
		parse_camera(line, &scene->camera, scene_error, line_num);
	else if (*line == 'l')
		parse_light(line, &scene->light, scene_error, line_num);
	else
		parse_invalid_element(line, scene_error, line_num);
}
