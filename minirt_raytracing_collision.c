/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_collision.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:13:06 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/09 14:04:20 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_sphere(void *object, t_ray *ray)
{
	t_sphere	*sp;
	t_coord		sp_to_origin;
	float		time[2];

	sp = (t_sphere *)object;
	sp_to_origin = v_subtract(ray->origin, sp->position);
	bhaskara(v_dot_product(ray->orient, ray->orient),
		2 * v_dot_product(ray->orient, sp_to_origin),
		v_dot_product(sp_to_origin, sp_to_origin) - pow(sp->diameter, 2) / 4,
		time);
	arrange_valid_root(time);
	if (ray->hit_time > time[0] && time[0] >= 0)
	{
		ray->hit_time = time[0];
		ray->hit_point = calc_hit_point(ray);
		ray->hit_normal = v_normalize(v_subtract(ray->hit_point, sp->position));
		ray->hit_color = sp->color;
	}
}
