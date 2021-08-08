/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:09:37 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/08 17:52:54 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_light(t_ray *ray, t_ray *shade, t_light ambi, t_light light)
{
	float	diffuse;

	ray->hit_color = c_product(ray->hit_color, ambi.color);
	diffuse = v_dot(shade->orient, ray->hit_normal);
	if (diffuse >= 0)
		ray->hit_color = c_scale(ray->hit_color,
			ambi.ratio + (light.ratio + 0.25) * diffuse * 0.75);
	else
		ray->hit_color = c_scale(ray->hit_color,
			ambi.ratio + (diffuse * 0.5));
	if (shade->hit_time >= v_module(v_subtract(light.position, shade->origin))
		|| v_dot(shade->orient, ray->hit_normal) < 0)
		return ;
	ray->hit_color = c_scale(ray->hit_color, 1 - 0.75 * light.ratio);
	(void)ambi;
}
