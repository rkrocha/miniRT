/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:16:20 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/01 09:13:50 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_picker(t_uchar red, t_uchar green, t_uchar blue)
{
	return (red << 16 | green << 8 | blue);
}

void	create_image(t_minilibx *mlx, int width, int height)
{
	mlx->img_ptr = mlx_new_image(mlx->ptr, width, height);
	mlx->img_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
}

void	putpixel_image(t_minilibx *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->img_addr + (y * mlx->line_len + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	fill_image(t_minilibx *mlx, t_scene *scene, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= scene->render_height)
	{
		while (x <= scene->render_width)
		{
			putpixel_image(mlx, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}
