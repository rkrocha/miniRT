/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:50:16 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/16 14:18:50 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(char *line, t_list **object, bool *error, int line_num)
{
	t_cylinder	*new_cylinder;
	char	*original_line;

	original_line = line;
	new_cylinder = (t_cylinder *)malloc_check(sizeof(t_cylinder));
	ft_bzero(new_cylinder, (sizeof(new_cylinder)));
	new_cylinder->id = TYPE_CYLINDER;
	if (!parse_position(&new_cylinder->position, &line, line_num)
		|| !parse_orientation(&new_cylinder->orient, &line, line_num)
		|| !parse_rgb(&new_cylinder->color, &line, line_num))
		*error = true;
	if (!get_next_float(&new_cylinder->diameter, &line)
		|| !get_next_float(&new_cylinder->height, &line))
	{
		print_scene_error(SCENE_DIMENSION, line_num);
		*error = true;
	}
	if (!(*object))
		*object = ft_lstnew(new_cylinder);
	else
		ft_lstadd_back(object, ft_lstnew(new_cylinder));
	if (MINIRT_DEBUG)
		debug_cylinder(original_line, *new_cylinder, line_num);
}

void	parse_plane(char *line, t_list **object, bool *error, int line_num)
{
	t_plane	*new_plane;
	char	*original_line;

	original_line = line;
	new_plane = (t_plane *)malloc_check(sizeof(t_plane));
	ft_bzero(new_plane, (sizeof(new_plane)));
	new_plane->id = TYPE_PLANE;
	if (!parse_position(&new_plane->position, &line, line_num)
		|| !parse_orientation(&new_plane->orient, &line, line_num)
		|| !parse_rgb(&new_plane->color, &line, line_num))
		*error = true;
	if (!(*object))
		*object = ft_lstnew(new_plane);
	else
		ft_lstadd_back(object, ft_lstnew(new_plane));
	if (MINIRT_DEBUG)
		debug_plane(original_line, *new_plane, line_num);
}
