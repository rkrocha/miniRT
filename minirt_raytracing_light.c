/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:09:37 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/06 12:39:06 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_light(t_ray *ray, t_light ambi, t_light light)
{
	float	diffuse;

	diffuse = v_dot(v_normalize(
		v_subtract(light.position, ray->hit_point)), ray->hit_normal);
	if (diffuse >= 0)
		ray->hit_color = c_product(
			ray->hit_color, ambi.ratio + light.ratio * diffuse);
	else
		ray->hit_color = c_product(
			ray->hit_color, ambi.ratio + 0.35 * diffuse);
}

void	calc_shade(t_ray *ray, t_ray *shade, t_light ambi, t_light light)
{
	if (v_dot(ray->hit_normal, shade->orient) <= 0 ||
		shade->hit_time >= v_module(v_subtract(light.position, shade->origin)))
		return ;
	ray->hit_color = c_product(ray->hit_color, light.ratio * ambi.ratio);
}

void	init_shade(t_ray *ray, t_ray *shade, t_light light)
{
	ft_bzero(shade, sizeof(t_ray));
	shade->origin = ray->hit_point;
	shade->orient = v_subtract(light.position, shade->origin);
	shade->hit_time = v_module(shade->orient);
	shade->orient = v_normalize(shade->orient);
}
