/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_extra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:36:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/08 20:10:46 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bhaskara(float a, float b, float c, float *root)
{
	float	sqrt_delta;
	float	temp;

	sqrt_delta = sqrt(b * b - 4 * a * c);
	root[0] = (-b - sqrt_delta) / (2 * a);
	root[1] = (-b + sqrt_delta) / (2 * a);
	if (root[1] < root[0] && root[1] >= 0)
	{
		temp = root[0];
		root[0] = root[1];
		root[1] = temp;
	}
}
