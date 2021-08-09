/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:08:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 01:54:07 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_image(t_scene *scene, t_camera *cam)
{
	int		x;
	int		y;
	t_ray	ray;

	x = 0;
	y = 0;
	calc_aux_geometry(cam, scene->res_x, scene->res_y);
	printf("%s\n", "Rendering new image...");
	while (y <= scene->res_y)
	{
		while (x <= scene->res_x)
		{
			calc_ray(&ray, cam,
				(float)x / scene->res_x, (float)y / scene->res_y);
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
	mlx.ptr = mlx_init();
	mlx.scene = scene;
	mlx.active_cam = scene->camera;
	check_adjust_window_resolution(&mlx, scene);
	mlx.window = mlx_new_window(mlx.ptr,
			scene->res_x, scene->res_y, "miniRT");
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
	}
	else
		print_minirt_usage();
	return (0);
}

// 	reorganize main to avoid duplicate function calls
