/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_extra.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:36:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/06 14:44:11 by rkochhan         ###   ########.fr       */
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

static bool	point_in_square(t_ray *ray, t_square *sq, float time)
{
	t_coord	n;
	t_coord	u;
	t_coord	v;
	t_coord	hit;
	t_coord	result;

	hit = v_add(ray->origin, v_scale(ray->orient, time));
	hit = v_subtract(hit, sq->position);
	n = sq->orient;
	if (n.y == 1 || n.y == -1)
		u = v_create(1, 0, 0);
	else
		u = v_normalize(v_cross(v_create(0, -1, 0), n));
	v = v_cross(n, u);
	result.x = u.x * hit.x + v.x * hit.y + n.x * hit.z;
	result.y = u.y * hit.x + v.y * hit.y + n.y * hit.z;
	if (fabs(result.x) < (sq->side / 2) && fabs(result.y) < (sq->side / 2))
		return (true);
	return (false);
}

bool	rt_square(void *object, t_ray *ray)
{
	t_square	*sq;
	float		denom;
	float		time;

	sq = (t_square *)object;
	denom = v_dot(sq->orient, ray->orient);
	time = v_dot(v_subtract(sq->position, ray->origin), sq->orient) / denom;
	if ((denom > -FLOAT_EPSILON && denom < FLOAT_EPSILON) ||
			time > ray->hit_time || time < FLOAT_EPSILON ||
			point_in_square(ray, sq, time) == false)
		return (false);
	ray->hit_time = time;
	ray->hit_point = calc_hit_point(ray);
	ray->hit_normal = sq->orient;
	if (v_dot(ray->orient, sq->orient) > 0)
		ray->hit_normal = v_scale(ray->hit_normal, -1);
	ray->hit_color = sq->color;
	ray->hit_obj = object;
	return (true);
}

static bool	point_in_triangle(t_ray *ray, t_triangle *tr, t_coord norm,
	float time)
{
	t_coord	hit;

	// if (v_dot(norm, ray->orient) > 0)
	// 	norm = v_scale(norm, -1);
	hit = v_add(ray->origin, v_scale(ray->orient, time));
	if (v_dot(v_cross(v_subtract(tr->point_b, tr->point_a),
			v_subtract(hit, tr->point_a)), norm) > 0 &&
			v_dot(v_cross(v_subtract(tr->point_c, tr->point_b),
			v_subtract(hit, tr->point_b)), norm) > 0 &&
			v_dot(v_cross(v_subtract(tr->point_a, tr->point_c),
			v_subtract(hit, tr->point_c)), norm) > 0)
		return (true);
	return (false);
}

bool	rt_triangle(void *object, t_ray *ray)
{
	t_triangle	*tr;
	t_coord		normal;
	float		denom;
	float		time;

	tr = (t_triangle *)object;
	normal = v_normalize(v_cross(v_subtract(tr->point_b, tr->point_a),
		v_subtract(tr->point_a, tr->point_c)));
	if (v_dot(ray->orient, normal) > 0)
		normal = v_scale(normal, -1);
	denom = v_dot(normal, ray->orient);
	time = v_dot(v_subtract(tr->point_a, ray->origin), normal) / denom;
	if ((denom > -FLOAT_EPSILON && denom < FLOAT_EPSILON) ||
			time > ray->hit_time || time < FLOAT_EPSILON ||
			point_in_triangle(ray, tr, normal, time) == false)
		return (false);
	ray->hit_time = time;
	ray->hit_point = calc_hit_point(ray);
	ray->hit_normal = normal;
	// if (v_dot(ray->orient, normal) > 0)
	// 	ray->hit_normal = v_scale(ray->hit_normal, -1);
	ray->hit_color = tr->color;
	ray->hit_obj = object;
	return (true);
}
