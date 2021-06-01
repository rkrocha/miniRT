/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:17:23 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/01 10:22:37 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_scene(t_scene *scene)
{
	ft_lstclear(&scene->camera, free);
	ft_lstclear(&scene->object, free);
	ft_lstclear(&scene->light, free);
}

static bool	check_scene_variables(t_scene scene)
{
	if (!scene.defined_resolution || !scene.defined_amblight)
	{
		if (!scene.defined_resolution)
			print_scene_error(SCENE_NO_RES, 0);
		if (!scene.defined_amblight)
			print_scene_error(SCENE_NO_AMBL, 0);
		return (false);
	}
	if (!scene.camera)
		print_warning(SCENE_WARN_NO_CAM);
	if (scene.camera && !scene.object)
		print_warning(SCENE_WARN_NO_OBJ);
	if (scene.camera && scene.defined_amblight
		&& (scene.ambient.ratio >= 0 && scene.ambient.ratio <= 0.2))
		print_warning(SCENE_WARN_DARK);
	return (true);
}

static bool	open_file(const char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		print_system_error(SYSTEM_OPEN);
		return (false);
	}
	return (true);
}

static bool	check_file_extension(const char *file)
{
	char	*extension;

	extension = ft_strchr(file, '.');
	if (extension && !ft_strncmp(extension, ".rt", 4))
		return (true);
	print_scene_error(SCENE_EXT, 0);
	return (false);
}

/*
** Scene parsing starts as long as scene file extension is valid and this file
** is opened without system errors. Any system errors cause the parsing to stop.
**
** Flaws contained inside the scene file, such as invalid type identifiers,
** invalid number types or ranges, or multiple inclusions of types that should
** be unique, will cause parsing to continue until EOF, printing all errors
** encountered and only then stopping execution.
*/
void	parse_scene(const char *file, t_scene *scene)
{
	int		fd;
	int		gnl_return;
	bool	scene_error;
	char	*line;

	if (!check_file_extension(file) || !open_file(file, &fd))
		exit(EXIT_FAILURE);
	scene_error = false;
	gnl_return = 1;
	while (gnl_return > 0)
	{
		gnl_return = get_next_line(fd, &line);
		if (gnl_return == -1)
		{
			print_system_error(SYSTEM_GNL);
			break ;
		}
		parse_by_type(line, scene, &scene_error);
		ft_strdel(&line);
	}
	if (!check_scene_variables(*scene) || scene_error || gnl_return == -1)
	{
		free_scene(scene);
		exit(EXIT_FAILURE);
	}
}
