/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:54:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/01 10:23:40 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_adjust_window_resolution(t_minilibx *mlx, t_scene *scene)
{
	int	max_x_res;
	int	max_y_res;

	mlx_get_screen_size(mlx->ptr, &max_x_res, &max_y_res);
	if (scene->render_width <= max_x_res && scene->render_height <= max_y_res)
		return ;
	if (scene->render_width > max_x_res)
	{
		scene->render_width = max_x_res;
		print_warning(SCENE_WARN_RES_X);
	}
	if (scene->render_height > max_y_res)
	{
		scene->render_height = max_y_res;
		print_warning(SCENE_WARN_RES_Y);
	}
}

void	display_manager(t_minilibx *mlx)
{
	static int	camera_count = -1;
	static int	active_cam_num = 1;

	if (!(mlx->active_cam))
		return ; //		print no camera warning
	if (camera_count == -1)
		camera_count = ft_lstsize(mlx->first_cam);
	if (mlx->active_cam->next)
	{
		mlx->active_cam = mlx->active_cam->next;
		active_cam_num++;
	}
	else
	{
		mlx->active_cam = mlx->first_cam;
		active_cam_num = 1;
	}
	// print active_cam_num/camera_count
	// MAKE DOUBLE LINKED LIST
}
