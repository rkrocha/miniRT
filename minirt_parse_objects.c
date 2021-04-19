/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:50:16 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/19 16:50:30 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(char *line, t_list **object, bool *error, int line_num)
{
	t_cylinder	*new_cylinder;
	char		**str_array;

	if (ft_str_word_count(line) < 6)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	new_cylinder = (t_cylinder *)malloc_check(sizeof(t_cylinder));
	ft_bzero(new_cylinder, (sizeof(new_cylinder)));
	new_cylinder->id = TYPE_CYLINDER;
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_position(&new_cylinder->position, str_array[1], error, line_num);
	parse_orient(&new_cylinder->orient, str_array[2], error, line_num);
	new_cylinder->diameter = ft_atof(str_array[3]);
	new_cylinder->height = ft_atof(str_array[4]);
	if (new_cylinder->diameter <= 0 || new_cylinder->height <= 0)
	{
		print_scene_error(SCENE_DIMENSION, line_num);
		*error = true;
	}
	parse_rgb(&new_cylinder->color, str_array[5], error, line_num);
	ft_lstadd_back(object, ft_lstnew(new_cylinder));
	ft_split_free(&str_array);
	if (MINIRT_DEBUG)
		debug_cylinder(line, *new_cylinder, line_num);
}

void	parse_plane(char *line, t_list **object, bool *error, int line_num)
{
	t_plane	*new_plane;
	char	**str_array;

	if (ft_str_word_count(line) < 4)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	new_plane = (t_plane *)malloc_check(sizeof(t_plane));
	ft_bzero(new_plane, (sizeof(new_plane)));
	new_plane->id = TYPE_PLANE;
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_position(&new_plane->position, str_array[1], error, line_num);
	parse_orient(&new_plane->orient, str_array[2], error, line_num);
	parse_rgb(&new_plane->color, str_array[3], error, line_num);
	ft_lstadd_back(object, ft_lstnew(new_plane));
	ft_split_free(&str_array);
	if (MINIRT_DEBUG)
		debug_plane(line, *new_plane, line_num);
}

void	parse_sphere(char *line, t_list **object, bool *error, int line_num)
{
	t_sphere	*new_sphere;
	char		**str_array;

	if (ft_str_word_count(line) < 4)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	new_sphere = (t_sphere *)malloc_check(sizeof(t_sphere));
	ft_bzero(new_sphere, (sizeof(new_sphere)));
	new_sphere->id = TYPE_SPHERE;
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_position(&new_sphere->position, str_array[1], error, line_num);
	new_sphere->diameter = ft_atof(str_array[2]);
	if (new_sphere->diameter <= 0)
	{
		print_scene_error(SCENE_DIMENSION, line_num);
		*error = true;
	}
	parse_rgb(&new_sphere->color, str_array[3], error, line_num);
	ft_lstadd_back(object, ft_lstnew(new_sphere));
	ft_split_free(&str_array);
	if (MINIRT_DEBUG)
		debug_sphere(line, *new_sphere, line_num);
}

void	parse_square(char *line, t_list **object, bool *error, int line_num)
{
	t_square	*new_square;
	char		**str_array;

	if (ft_str_word_count(line) < 5)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	new_square = (t_square *)malloc_check(sizeof(t_square));
	ft_bzero(new_square, (sizeof(new_square)));
	new_square->id = TYPE_SQUARE;
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_position(&new_square->position, str_array[1], error, line_num);
	parse_orient(&new_square->orient, str_array[2], error, line_num);
	new_square->side = ft_atof(str_array[3]);
	if (new_square->side <= 0)
	{
		print_scene_error(SCENE_DIMENSION, line_num);
		*error = true;
	}
	parse_rgb(&new_square->color, str_array[4], error, line_num);
	ft_lstadd_back(object, ft_lstnew(new_square));
	ft_split_free(&str_array);
	if (MINIRT_DEBUG)
		debug_square(line, *new_square, line_num);
}

void	parse_triangle(char *line, t_list **object, bool *error, int line_num)
{
	t_triangle	*new_triangle;
	char		**str_array;

	if (ft_str_word_count(line) < 5)
	{
		print_scene_error(SCENE_FEW_ARGS, line_num);
		*error = true;
		return ;
	}
	new_triangle = (t_triangle *)malloc_check(sizeof(t_triangle));
	ft_bzero(new_triangle, (sizeof(new_triangle)));
	new_triangle->id = TYPE_TRIANGLE;
	str_array = ft_split(ft_str_remove_blanks(line), ' ');
	parse_position(&new_triangle->point_a, str_array[1], error, line_num);
	parse_position(&new_triangle->point_b, str_array[2], error, line_num);
	parse_position(&new_triangle->point_c, str_array[3], error, line_num);
	parse_rgb(&new_triangle->color, str_array[4], error, line_num);
	ft_lstadd_back(object, ft_lstnew(new_triangle));
	ft_split_free(&str_array);
	if (MINIRT_DEBUG)
		debug_triangle(line, *new_triangle, line_num);
}
