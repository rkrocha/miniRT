/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:54:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/09 15:29:59 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_adjust_window_resolution(t_minilibx *mlx, t_scene *scene)
{
	int	max_x_res;
	int	max_y_res;

	mlx_get_screen_size(mlx->ptr, &max_x_res, &max_y_res);
	if (scene->res_x <= max_x_res && scene->res_y <= max_y_res)
		return ;
	if (scene->res_x > max_x_res)
	{
		scene->res_x = max_x_res;
		print_warning(SCENE_WARN_RES_X);
	}
	if (scene->res_y > max_y_res)
	{
		scene->res_y = max_y_res;
		print_warning(SCENE_WARN_RES_Y);
	}
}

static void	render_manager(t_minilibx *mlx)
{
	t_image	*active_image;

	active_image = &((t_camera *)mlx->active_cam->content)->image;
	if (active_image->is_rendered == true)
	{
		refresh_display(mlx);
		printf("%s\n\n", "Image already rendered. Displaying.");
		return ;
	}
	create_image(mlx);
	render_image(mlx->scene, (t_camera *)(mlx->active_cam->content));
	refresh_display(mlx);
}

void	display_manager(t_minilibx *mlx)
{
	static int	cam_count = -1;
	static int	active_cam_num = 1;

	if (cam_count == -1)
		cam_count = ft_lstsize(mlx->scene->camera);
	if (mlx->active_cam->next)
	{
		mlx->active_cam = mlx->active_cam->next;
		active_cam_num++;
	}
	else if (cam_count > 1)
	{
		mlx->active_cam = mlx->scene->camera;
		active_cam_num = 1;
	}
	if (cam_count > 1)
	{
		printf("%s %d/%d\n", "Switching to camera", active_cam_num, cam_count);
		render_manager(mlx);
	}
	else
		printf("%s\n\n", "No other camera is defined!");
}
