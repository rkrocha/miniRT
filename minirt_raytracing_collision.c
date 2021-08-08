/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_collision.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:13:06 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/08 20:08:35 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	cy_calc(t_ray ray, t_cylinder cy, float *y, bool ret[2])
{
	t_coord	v[2];
	t_coord	v_cy2ray;
	float	time[2];
	float	dist[2];

	v[0] = v_subtract(ray.orient, v_scale(
		cy.orient, v_dot(ray.orient, cy.orient)));
	v[1] = v_subtract(v_subtract(ray.origin, cy.position), v_scale(
		cy.orient, v_dot(v_subtract(ray.origin, cy.position), cy.orient)));
	bhaskara(v_dot(v[0], v[0]), 2 * v_dot(v[0], v[1]),
				v_dot(v[1], v[1]) - pow(cy.diameter / 2, 2), time);
	v_cy2ray = v_subtract(cy.position, ray.origin);
	dist[0] = v_dot(cy.orient, v_subtract(v_scale(
		ray.orient, time[0]), v_cy2ray));
	dist[1] = v_dot(cy.orient, v_subtract(
		v_scale(ray.orient, time[1]), v_cy2ray));
	ret[0] = (dist[0] >= 0 && dist[0] <= cy.height && time[0] > FLOAT_EPSILON);
	ret[1] = (dist[1] >= 0 && dist[1] <= cy.height && time[1] > FLOAT_EPSILON);
	if (ret[0] == false & ret[1] == true)
	{
		*y = dist[1];
		return (time[1]);
	}
	*y = dist[0];
	return (time[0]);
}

bool	rt_cylinder(void *object, t_ray *ray)
{
	t_cylinder	*cy;
	bool		ret[2];
	float		time;
	float		y;

	cy = (t_cylinder *)object;
	time = cy_calc(*ray, *cy, &y, ret);
	if ((ret[0] || ret[1]) && ray->hit_time > time && time > FLOAT_EPSILON)
	{
		ray->hit_time = time;
		ray->hit_point = calc_hit_point(ray);
		ray->hit_normal = v_normalize(v_subtract(ray->hit_point,
			v_add(v_scale(cy->orient, y), cy->position)));
		if (ret[0] == false & ret[1] == true)
			ray->hit_normal = v_scale(ray->hit_normal, -1);
		ray->hit_color = cy->color;
		ray->hit_obj = object;
	}
	return (ret[0] || ret[1]);
}

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
	if (ray->hit_time > time && time > FLOAT_EPSILON)
	{
		ray->hit_time = time;
		ray->hit_point = calc_hit_point(ray);
		ray->hit_normal = pl->orient;
		if (v_dot(ray->orient, pl->orient) > 0)
			ray->hit_normal = v_scale(ray->hit_normal, -1);
		ray->hit_color = pl->color;
		ray->hit_obj = object;
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
	if (ray->hit_time > time[0] && time[0] > -FLOAT_EPSILON)
	{
		ray->hit_time = time[0];
		ray->hit_point = calc_hit_point(ray);
		ray->hit_normal = v_normalize(v_subtract(ray->hit_point, sp->position));
		if (v_dot(ray->orient, ray->hit_normal) > 0)
			ray->hit_normal = v_scale(ray->hit_normal, -1);
		ray->hit_color = sp->color;
		ray->hit_obj = object;
		return (true);
	}
	return (false);
}

/////    MAKE ALL OF THESE UP TO A STANDARD
