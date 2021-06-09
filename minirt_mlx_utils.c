/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:16:20 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/06 16:12:07 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_image(t_minilibx *mlx)
{
	t_image	*aux_image;

	aux_image = &((t_camera *)mlx->active_cam->content)->image;
	aux_image->ptr = mlx_new_image(mlx->ptr,
			mlx->scene->render_width, mlx->scene->render_height);
	//   CHECK IMAGE ALLOCATION?
	aux_image->addr = mlx_get_data_addr(aux_image->ptr,
			&aux_image->bpp, &aux_image->line_len, &aux_image->endian);
}

void	lst_image_destroy(t_minilibx *mlx, t_list *lst)
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		if (((t_camera *)lst->content)->image.is_rendered == true)
			mlx_destroy_image(mlx->ptr, ((t_camera *)lst->content)->image.ptr);
		lst = lst->next;
	}
}

int	color_picker(t_uchar red, t_uchar green, t_uchar blue)
{
	return (red << 16 | green << 8 | blue);
}

void	putpixel_image(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	fill_image(t_minilibx *mlx, int color)
{
	t_image	*aux_image;
	int		x;
	int		y;

	aux_image = &((t_camera *)mlx->active_cam->content)->image;
	x = 0;
	y = 0;
	while (y <= mlx->scene->render_height)
	{
		while (x <= mlx->scene->render_width)
		{
			putpixel_image(aux_image, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}
