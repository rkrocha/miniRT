/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:23:00 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 11:33:38 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_picker(t_uchar red, t_uchar green, t_uchar blue)
{
	return (red << 16 | green << 8 | blue);
}

int	c_product(int color_a, int color_b)
{
	int	r;
	int	g;
	int	b;

	r = (((float)(color_a >> 0x10) / 0xFF)
			* ((float)(color_b >> 0x10) / 0xFF)) * 0xFF;
	g = (((float)((color_a >> 0x08) & 0xFF) / 0xFF)
			* ((float)((color_b >> 0x08) & 0xFF) / 0xFF)) * 0xFF;
	b = (((float)(color_a & 0xFF) / 0xFF)
			* ((float)(color_b & 0xFF) / 0xFF)) * 0xFF;
	return ((r << 16) | (g << 8) | b);
}

int	c_scale(int color, float coef)
{
	int	mask;
	int	r;
	int	g;
	int	b;

	mask = 255;
	r = coef * ((color & (mask << 16)) >> 16);
	g = coef * ((color & (mask << 8)) >> 8);
	b = coef * (color & mask);
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}
