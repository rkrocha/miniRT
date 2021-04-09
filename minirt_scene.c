/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:17:23 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/09 18:34:22 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_scene(t_scene *scene)
{
	ft_lstclear(&scene->camera, free);
	ft_lstclear(&scene->object, free);
	ft_lstclear(&scene->light, free);
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

	extension = ft_strrchr(file, '.');
	if (extension && !ft_strncmp(extension, ".rt", 4))
		return (true);
	print_scene_error(SCENE_EXT, NULL, 0);
	return (false);
}

static void	parse_element(char *line, t_scene *scene, bool *scene_error)
{
	static size_t	line_count;

	line_count++;
	if (*line == '\0' || *line == '#')
		return ;
	printf("%s\n", line);
	(void)scene;
	(void)scene_error;
}

void	parse_scene(const char *file, t_scene *scene)
{
	int		fd;
	int		gnl_return;
	bool	scene_error;
	char	*line;

	if (!check_file_extension(file) || !open_file(file, &fd))
		exit(EXIT_FAILURE);
	ft_bzero(scene, sizeof(t_scene));
	gnl_return = 1;
	while (gnl_return > 0)
	{
		gnl_return = get_next_line(fd, &line);
		if (gnl_return == -1)
		{
			print_system_error(SYSTEM_GNL);
			break ;
		}
		parse_element(line, scene, &scene_error);
		free(line);
	}
	if (scene_error || gnl_return == -1)
	{
		free_scene(scene);
		exit(EXIT_FAILURE);
	}
}
