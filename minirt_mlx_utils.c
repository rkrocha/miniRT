/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:16:20 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/20 16:33:27 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_picker(t_uchar red, t_uchar green, t_uchar blue)
{
	return (red << 16 | green << 8 | blue);
}

void	paint_pixel(t_image *img, int x, int y, int color)
{
	char	*pix;

	pix = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pix = color;
}

void	fill_image(t_image *img, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= img->height)
	{
		while (x <= img->width)
		{
			paint_pixel(img, x, y, color);
			x++;
		}
		y++;
		x = 0;
	}
}

void	create_image(t_image *img, void *mlx, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	img->width = width;
	img->height = height;
}
