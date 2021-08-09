/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx_hook_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:10:48 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 02:35:26 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_window(t_minilibx *mlx)
{
	printf("%s\n", "Shutting down miniRT. Bye! :)");
	mlx_destroy_window(mlx->ptr, mlx->window);
	lst_image_destroy(mlx, mlx->scene->camera);
	free_scene(mlx->scene);
	mlx->window = NULL;
	exit(1);
	return (0);
}

int	keyboard_input(int keycode, t_minilibx *mlx)
{
	if (keycode == 0xff1b)
		close_window(mlx);
	else if (keycode == 0xff09 && mlx->active_cam != NULL)
		display_manager(mlx);
	return (0);
}

int	refresh_display(t_minilibx *mlx)
{
	if (mlx->active_cam == NULL)
		return (-1);
	mlx_put_image_to_window(mlx->ptr, mlx->window,
		((t_camera *)mlx->active_cam->content)->image.ptr, 0, 0);
	return (0);
}
