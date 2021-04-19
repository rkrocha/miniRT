/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_debug_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:57:10 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/19 16:53:42 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	debug_line(char *line, int line_num)
{
	char	str[128];
	char	*line_num_str;

	ft_strlcpy(str, "Scene line ", sizeof(str));
	ft_strlcat(str, line_num_str = ft_itoa(line_num), sizeof(str));
	free(line_num_str);
	ft_strlcat(str, " is: ", sizeof(str));//REMAKE THIS SECTION?
	ft_strlcat(str, line, sizeof(str));
	ft_putendl_fd(str, 2);
}

void	debug_res(char *line, t_scene scene, int line_num)
{
	if (line && line_num)
		debug_line(line, line_num);
	printf("Resolution set to %dx%d\n\n",
		scene.render_width, scene.render_height);
}

void	debug_ambl(char *line, t_light ambient, int line_num)
{
	if (line && line_num)
		debug_line(line, line_num);
	printf("Parsed ambient light of ratio %.2f, RGB %#.8x\n\n",
		ambient.ratio, ambient.color);
}

void	debug_camera(char *line, t_camera camera, int line_num)
{
	if (line && line_num)
		debug_line(line, line_num);
	printf("Parsed camera at position %.1f %.1f %.1f, ",
		camera.position.x, camera.position.y, camera.position.z);
	printf("orientation %.1f %.1f %.1f, ",
		camera.orient.x, camera.orient.y, camera.orient.z);
	printf("FOV %.f\n\n", camera.fov);
}

void	debug_light(char *line, t_light light, int line_num)
{
	if (line && line_num)
		debug_line(line, line_num);
	printf("Parsed light at position %.1f %.1f %.1f, ",
		light.position.x, light.position.y, light.position.z);
	printf("ratio %.2f, RGB %#.8x\n\n",
		light.ratio, light.color);
}
