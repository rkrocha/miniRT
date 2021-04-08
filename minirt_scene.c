/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:17:23 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/08 09:33:25 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_file_extension(const char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (extension && !ft_strncmp(extension, ".rt", 3))
		return (true);
	print_scene_error(SCENE_EXT, NULL, 0);
	return (false);
}

bool	read_scene(const char *file, t_scene *scene)
{
	// int	fd;
	// int	ret;
	(void)scene;

	if (!check_file_extension(file))
		return (false);
	return (true);
}
