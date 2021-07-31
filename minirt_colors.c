/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:23:00 by rkochhan          #+#    #+#             */
/*   Updated: 2021/07/31 11:46:43 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	c_add(int color_a, int color_b)
{
	int mask;
	int	r;
	int	g;
	int b;

	mask = 255;
	r = ((color_a & (mask << 16)) + (color_b & (mask << 16))) & (mask << 16);
	g = ((color_a & (mask << 8)) + (color_b & (mask << 8))) & (mask << 8);
	b = ((color_a & mask) + (color_b & mask)) & mask;
	return (r | g | b);
}

int	c_product(int color, float coef)
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
