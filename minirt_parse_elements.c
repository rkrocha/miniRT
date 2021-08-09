/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:41:02 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 03:16:29 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parse_res(char *line, t_scene *scene, bool *error, int line_num)
{
	char	**str_array;

	if (scene->defined_resolution || ft_str_word_count(line) < 3)
	{
		if (scene->defined_resolution)
			print_scene_error(SCENE_MULT_RES, line_num);
		else
			print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	scene->res_x = ft_atoi(str_array[1]);
	scene->res_y = ft_atoi(str_array[2]);
	scene->defined_resolution = true;
	if (scene->res_x <= 0 || scene->res_y <= 0)
	{
		print_scene_error(SCENE_RES, line_num);
		*error = true;
	}
	ft_split_free(&str_array);
}

static void	parse_ambl(char *line, t_scene *scene, bool *error, int line_num)
{
	char	**str_array;

	if (scene->defined_amblight)
	{
		print_scene_error(SCENE_MULT_AMBL, line_num);
		*error = true;
		return ;
	}
	if (ft_str_word_count(line) < 3)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_light_ratio(&scene->ambient.ratio, str_array[1], error, line_num);
	parse_rgb(&scene->ambient.color, str_array[2], error, line_num);
	scene->defined_amblight = true;
	ft_split_free(&str_array);
}

static void	parse_camera(char *line, t_list **camera, bool *error, int line_num)
{
	t_camera	*new_cam;
	char		**str_array;

	if (ft_str_word_count(line) < 4)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	new_cam = (t_camera *)malloc_check(sizeof(t_camera));
	ft_bzero(new_cam, sizeof(t_camera));
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_position(&new_cam->position, str_array[1], error, line_num);
	parse_orient(&new_cam->orient, str_array[2], error, line_num);
	new_cam->fov = ft_atof(str_array[3]);
	if (new_cam->fov <= 0 || new_cam->fov > 180)
	{
		print_scene_error(SCENE_CAM_FOV, line_num);
		*error = true;
	}
	ft_lstadd_back(camera, ft_lstnew(new_cam));
	ft_split_free(&str_array);
}

static void	parse_light(char *line, t_list **light, bool *error, int line_num)
{
	t_light	*new_light;
	char	**str_array;

	if (ft_str_word_count(line) < 4)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	new_light = (t_light *)malloc_check(sizeof(t_light));
	ft_bzero(new_light, (sizeof(t_light)));
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_position(&new_light->position, str_array[1], error, line_num);
	parse_light_ratio(&new_light->ratio, str_array[2], error, line_num);
	parse_rgb(&new_light->color, str_array[3], error, line_num);
	ft_lstadd_back(light, ft_lstnew(new_light));
	ft_split_free(&str_array);
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
	else if (*line == 'c' && *(line + 1) == 'y')
		parse_cylinder(line, &scene->object, scene_error, line_num);
	else if (*line == 'p' && *(line + 1) == 'l')
		parse_plane(line, &scene->object, scene_error, line_num);
	else if (*line == 's' && *(line + 1) == 'p')
		parse_sphere(line, &scene->object, scene_error, line_num);
	else if (*line == 'c' || *line == 'C')
		parse_camera(line, &scene->camera, scene_error, line_num);
	else if (*line == 'l' || *line == 'L')
		parse_light(line, &scene->light, scene_error, line_num);
	else
		parse_invalid_element(line, scene_error, line_num);
}
