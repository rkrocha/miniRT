/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:08:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/09 13:55:40 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_image(t_scene *scene, t_camera *cam)
{
	int		x;
	int		y;
	t_ray	ray; //   REGISTER?

	x = 0;
	y = 0;
	calc_aux_geometry(cam, scene->render_width, scene->render_height);
	printf("%s\n", "Rendering new image...");
	while (y <= scene->render_height)
	{
		while (x <= scene->render_width)
		{
			calc_ray(&ray, cam, x, y);
			raytrace(scene, &ray);
			putpixel_image(&cam->image, x, y, ray.hit_color);
			x++;
		}
		x = 0;
		y++;
	}
	printf("%s\n\n", "Rendered!");
	cam->image.is_rendered = true;
}

static void	run_mlx(t_scene *scene)
{
	t_minilibx	mlx;

	ft_bzero(&mlx, sizeof(mlx));
	mlx.ptr = mlx_init(); // 	quit in case of NULL return
	mlx.scene = scene;
	mlx.active_cam = scene->camera;
	check_adjust_window_resolution(&mlx, scene);
	mlx.window = mlx_new_window(mlx.ptr,
			scene->render_width, scene->render_height, "miniRT");

	if (mlx.active_cam != NULL)
	{
		create_image(&mlx);
		render_image(scene, (t_camera *)(mlx.active_cam->content));
	}

	mlx_key_hook(mlx.window, keyboard_input, &mlx);
	mlx_expose_hook(mlx.window, refresh_display, &mlx);
	mlx_hook(mlx.window, 33, 1L << 17, close_window, &mlx);


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
		//free_scene(&scene);		// REMOVE
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

// 	reorganize main to avoid duplicate function calls
