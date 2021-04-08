/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:08:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/08 09:45:24 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char const **argv)
{
	t_scene	scene;

	if (argc == 2)
	{
		read_scene(argv[1], &scene);
		// start_mlx(scene);
	}
	// else if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
	// {
	// 	read_scene(argv[1], &scene);
	// 	render_screenshot(scene);
	// }
	return (0);
}
