/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:08:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/01 10:23:52 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	define_mlx_hooks(t_minilibx *mlx, t_scene *scene)
// {
// 	mlx_hook(mlx->ptr, 33, 1L << 17, close_window, mlx);
// 	mlx_key_hook(window.ptr, keyboard_input, &window);
// }

static void	run_mlx(t_scene *scene)
{
	t_minilibx	mlx;

	ft_bzero(&mlx, sizeof(mlx));
	mlx.ptr = mlx_init();
	check_adjust_window_resolution(&mlx, scene);
	mlx.first_cam = scene->camera;
	mlx.active_cam = scene->camera;
	create_image(&mlx, scene->render_width, scene->render_height);
	mlx.window = mlx_new_window(mlx.ptr,
			scene->render_width, scene->render_height, "miniRT");

	mlx_loop(mlx.ptr);
}

int	main(int argc, const char **argv)
{
	t_scene	scene;

	if (MINIRT_DEBUG)
		ft_putendl_fd(DEBUG_MODE, 2);
	if (argc == 2)
	{
		ft_bzero(&scene, sizeof(t_scene));
		parse_scene(argv[1], &scene);
		run_mlx(&scene);
		free_scene(&scene);		// REMOVE
	}
	// else if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
	// {
	// 	ft_bzero(&scene, sizeof(t_scene));
	// 	parse_scene(argv[1], &scene);
	// 	render_to_bmp(scene);
	// }
	else
		print_minirt_usage();
	return (0);
}
