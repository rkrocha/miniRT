/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:09:37 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 01:45:56 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_light(t_ray *ray, t_ray *shade, t_light ambi, t_light light)
{
	float	diffuse;
	bool	in_shadow;

	ray->hit_color = c_product(ray->hit_color, ambi.color);
	diffuse = v_dot(shade->orient, ray->hit_normal);
	in_shadow = false;
	if (shade->hit_time < v_module(v_subtract(light.position, shade->origin)))
		in_shadow = true;
	if (diffuse >= 0 && !in_shadow)
		ray->hit_color = c_scale(ray->hit_color,
			ambi.ratio + (light.ratio * diffuse * 0.75));
	else
		ray->hit_color = c_scale(ray->hit_color,
			ambi.ratio + (diffuse * 0.25 * in_shadow));
	if (!in_shadow)
		return ;
	ray->hit_color = c_scale(ray->hit_color,
		1 - 0.75 * light.ratio * diffuse * 0.75);
}
