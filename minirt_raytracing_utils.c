/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:36:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/09 11:17:54 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bhaskara(float a, float b, float c, float *root)
{
	float	sqrt_part;

	sqrt_part = sqrt(pow(b, 2) - 4 * a * c);
	root[0] = (-b - sqrt_part) / (2 * a);
	root[1] = (-b + sqrt_part) / (2 * a);
}

void	arrange_valid_root(float *root)
{
	float	temp;

	if (root[1] < root[0] && root[1] >= 0)
	{
		temp = root[0];
		root[0] = root[1];
		root[1] = temp;
	}
}
