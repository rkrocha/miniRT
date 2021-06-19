/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:36:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/19 11:09:33 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bhaskara(float a, float b, float c, float *root)
{
	float	sqrt_part;

	sqrt_part = sqrt(b * b - 4 * a * c);
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

bool	point_in_square(t_ray *ray, t_square *sq, float time)
{
	t_coord	n;
	t_coord	u;
	t_coord	v;
	t_coord	hit;
	t_coord	result;

	hit = v_add(ray->origin, v_scale(ray->orient, time));
	hit = v_subtract(hit, sq->position);
	if (sq->orient.y == 1 || sq->orient.y == -1)
		u = v_create(1, 0, 0);
	else
		u = v_cross(v_create(0, -1, 0), sq->orient);
	v = v_cross(sq->orient, u);
	n = sq->orient;
	result.x = u.x * hit.x + v.x * hit.y + n.x * hit.z;
	result.y = u.y * hit.x + v.y * hit.y + n.y * hit.z;
	if (fabs(result.x) < (sq->side / 2) && fabs(result.y) < (sq->side / 2))
		return (true);
	return (false);
}
