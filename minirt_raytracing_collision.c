/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_collision.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:13:06 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/19 15:52:42 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	rt_plane(void *object, t_ray *ray)
{
	t_plane	*pl;
	float	denom;
	float	time;

	pl = (t_plane *)object;
	denom = v_dot(pl->orient, ray->orient);
	if (denom > -FLOAT_EPSILON && denom < FLOAT_EPSILON)
		return (false);
	time = v_dot(v_subtract(pl->position, ray->origin), pl->orient) / denom;
	if (ray->hit_time > time && time > 0)
	{
		ray->hit_time = time;
		ray->hit_point = calc_hit_point(ray);
		ray->hit_normal = pl->orient;
		if (v_dot(ray->orient, pl->orient) > 0)
			ray->hit_normal = v_scale(ray->hit_normal, -1);
		ray->hit_color = pl->color;
		return (true);
	}
	return (false);
}

bool	rt_sphere(void *object, t_ray *ray)
{
	t_sphere	*sp;
	t_coord		sp_to_origin;
	float		time[2];

	sp = (t_sphere *)object;
	sp_to_origin = v_subtract(ray->origin, sp->position);
	// bhaskara(v_dot(ray->orient, ray->orient),
	bhaskara(1,	//  REVIEW
		2 * v_dot(ray->orient, sp_to_origin),
		v_dot(sp_to_origin, sp_to_origin) - pow(sp->diameter, 2) / 4,
		time);
	arrange_valid_root(time);
	if (ray->hit_time > time[0] && time[0] > 0)
	{
		ray->hit_time = time[0];
		ray->hit_point = calc_hit_point(ray);
		ray->hit_normal = v_normalize(v_subtract(ray->hit_point, sp->position));
		if (v_dot(ray->orient, ray->hit_normal) > 0)
			ray->hit_normal = v_scale(ray->hit_normal, -1);
		ray->hit_color = sp->color;
		return (true);
	}
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
			time > ray->hit_time || time < 0 ||
			point_in_square(ray, sq, time) == false)
		return (false);
	ray->hit_time = time;
	ray->hit_point = calc_hit_point(ray);
	ray->hit_normal = sq->orient;
	if (v_dot(ray->orient, sq->orient) > 0)
		ray->hit_normal = v_scale(ray->hit_normal, -1);
	ray->hit_color = sq->color;
	return (true);
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
	denom = v_dot(normal, ray->orient);
	time = v_dot(v_subtract(tr->point_a, ray->origin), normal) / denom;
	if ((denom > -FLOAT_EPSILON && denom < FLOAT_EPSILON) ||
			time > ray->hit_time || time < 0 ||
			point_in_triangle(ray, tr, normal, time) == false)
		return (false);
	ray->hit_time = time;
	ray->hit_point = calc_hit_point(ray);
	ray->hit_normal = normal;
	if (v_dot(ray->orient, normal) > 0)
		ray->hit_normal = v_scale(ray->hit_normal, -1);
	ray->hit_color = tr->color;
	return (true);
}



/////    MAKE ALL OF THESE UP TO A STANDARD
