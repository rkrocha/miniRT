/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:09:37 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/06 17:54:30 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_light(t_ray *ray, t_ray *shade, t_light ambi, t_light light)
{
	float	diffuse;

	diffuse = v_dot(shade->orient, ray->hit_normal);
	if (diffuse >= 0)
		ray->hit_color = c_product(
			ray->hit_color, ambi.ratio + light.ratio * diffuse);
	else
		ray->hit_color = c_product(
			ray->hit_color, ambi.ratio + 0.35 * diffuse);
	if (shade->hit_time >= v_module(v_subtract(light.position, shade->origin))
		|| v_dot(shade->orient, ray->hit_normal) < 0)
		return ;
	ray->hit_color = c_product(ray->hit_color, 1 - light.ratio);
}
