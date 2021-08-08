/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:23:00 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/08 16:24:57 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	c_add(int color_a, int color_b)
{
	int	r;
	int	g;
	int b;

	r = ((color_a >> 0x10) + (color_b >> 0x10)) / 2;
	g = ((color_a >> 0x08 & 0xFF) + (color_b >> 0x08 & 0xFF)) / 2;
	b = ((color_a & 0xFF) + (color_b & 0xFF)) / 2;
	return ((r << 16) | (g << 8) | b);
}

int			c_product(int c1, int c2)
{
	int	r;
	int	g;
	int	b;

	r = (((float)(c1 >> 0x10) / 0xFF) *
			((float)(c2 >> 0x10) / 0xFF)) * 0xFF;
	g = (((float)((c1 >> 0x08) & 0xFF) / 0xFF) *
			((float)((c2 >> 0x08) & 0xFF) / 0xFF)) * 0xFF;
	b = (((float)(c1 & 0xFF) / 0xFF) *
			((float)(c2 & 0xFF) / 0xFF)) * 0xFF;
	return ((r << 0x10) | (g << 0x08) | b);
}

int	c_scale(int color, float coef)
{
	int mask;
	int r;
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
