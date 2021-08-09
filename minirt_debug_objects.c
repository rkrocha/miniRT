/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_debug_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:50:30 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 01:49:52 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	debug_cylinder(char *line, t_cylinder cylinder, int line_num)
{
	if (line && line_num)
		debug_line(line, line_num);
	printf("Parsed cylinder at position %.1f %.1f %.1f, ",
		cylinder.position.x, cylinder.position.y, cylinder.position.z);
	printf("orientation %.1f %.1f %.1f, ",
		cylinder.orient.x, cylinder.orient.y, cylinder.orient.z);
	printf("diameter %.1f, height %.1f, RGB %#.8x\n\n",
		cylinder.diameter, cylinder.height, cylinder.color);
}

void	debug_plane(char *line, t_plane plane, int line_num)
{
	if (line && line_num)
		debug_line(line, line_num);
	printf("Parsed plane at position %.1f %.1f %.1f, ",
		plane.position.x, plane.position.y, plane.position.z);
	printf("orientation %.1f %.1f %.1f, RGB %#.8x\n\n",
		plane.orient.x, plane.orient.y, plane.orient.z,
		plane.color);
}

void	debug_sphere(char *line, t_sphere sphere, int line_num)
{
	if (line && line_num)
		debug_line(line, line_num);
	printf("Parsed sphere at position %.1f %.1f %.1f, ",
		sphere.position.x, sphere.position.y, sphere.position.z);
	printf("diameter %.1f, RGB %#.8x\n\n",
		sphere.diameter, sphere.color);
}
