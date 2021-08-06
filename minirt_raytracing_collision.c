/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_collision.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:13:06 by rkochhan          #+#    #+#             */
/*   Updated: 2021/07/31 20:30:02 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	get_cylinder_roots(void *object, t_ray *ray, float *time)
// {
// 	float	a;
// 	float	b;
// 	float	c;

// 	a = 
// }

// bool	rt_cylinder(void *object, t_ray *ray)
// {
// 	t_cylinder	*cy;
// 	float		time[2];

// 	cy = (t_cylinder *)object;

// }

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
	if (ray->hit_time > time[0] && time[0] > FLOAT_EPSILON)
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
