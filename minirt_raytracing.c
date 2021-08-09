/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:23:11 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 02:03:41 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calc_aux_geometry(t_camera *cam, int res_x, int res_y)
{
	float	viewport_x;
	float	viewport_y;
	t_coord	n;
	t_coord	u;
	t_coord	v;

	viewport_x = 2 * tan(cam->fov / 180);
	viewport_y = viewport_x * res_y / res_x;
	n = v_normalize(v_scale(cam->orient, -1));
	if (fabs(cam->orient.y) > fabs(cam->orient.x)
		&& fabs(cam->orient.y) > fabs(cam->orient.z))
		u = v_cross(v_create(-1, 0, 0), n);
	else
		u = v_cross(v_create(0, -1, 0), n);
	v = v_cross(n, u);
	cam->pixel_x = v_scale(u, viewport_x);
	cam->pixel_y = v_scale(v, viewport_y);
	cam->img_origin = v_sub(cam->position, v_scale(cam->pixel_x, 0.5));
	cam->img_origin = v_sub(cam->img_origin, v_scale(cam->pixel_y, 0.5));
	cam->img_origin = v_sub(cam->img_origin, n);
}

t_coord	calc_hit_point(t_ray *ray)
{
	return (v_add(ray->origin, v_scale(ray->orient, ray->hit_time)));
}

void	calc_ray(t_ray *ray, t_camera *cam, float x, float y)
{
	ft_bzero(ray, sizeof(t_ray));
	ray->origin = cam->position;
	ray->orient = v_add(v_scale(cam->pixel_x, x), v_scale(cam->pixel_y, y));
	ray->orient = v_add(ray->orient, cam->img_origin);
	ray->orient = v_normalize(v_sub(ray->orient, ray->origin));
	ray->hit_time = INFINITY;
}

static void	init_shade(t_ray *ray, t_ray *shade, t_light light)
{
	ft_bzero(shade, sizeof(t_ray));
	shade->origin = ray->hit_point;
	shade->orient = v_sub(light.position, shade->origin);
	shade->hit_time = v_module(shade->orient);
	shade->orient = v_normalize(shade->orient);
}

void	raytrace(t_scene *scene, t_ray *ray)
{
	t_list					*obj;
	t_ray					shade;
	static	void (*const	func_ptr[5])(void *, t_ray *) = {
		rt_cylinder, rt_plane, rt_sphere};

	obj = scene->object;
	while (obj)
	{
		func_ptr[*(t_uchar *)(obj->content)](obj->content, ray);
		obj = obj->next;
	}
	if (ray->hit_time == INFINITY)
		return ;
	obj = scene->object;
	init_shade(ray, &shade, *(t_light *)(scene->light->content));
	while (obj)
	{
		func_ptr[*(t_uchar *)(obj->content)](obj->content, &shade);
		obj = obj->next;
	}
	calc_light(ray, &shade, scene->ambient,
		*(t_light *)(scene->light->content));
}
