/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:57:02 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/09 14:07:23 by rkochhan         ###   ########.fr       */
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

	viewport_x = 2 * tanf(cam->fov / 2);
	viewport_y = viewport_x * res_y / res_x;
	n = v_normalize(v_scale(cam->orient, -1));
	u = v_cross_product(v_create(0, 1, 0), n);
	v = v_cross_product(n, u);
	cam->pixel_x = v_scale(u, viewport_x / res_x);
	cam->pixel_y = v_scale(v, viewport_y / res_y);
	cam->img_origin = v_subtract(cam->position, v_scale(cam->pixel_x, 0.5));
	cam->img_origin = v_subtract(cam->img_origin, v_scale(cam->pixel_y, 0.5));
	cam->img_origin = v_subtract(cam->img_origin, n);
}

void	calc_ray(t_ray *ray, t_camera *cam, float x, float y)
{
	ft_bzero(ray, sizeof(t_ray));
	ray->origin = cam->position;
	ray->orient = v_add(v_scale(cam->pixel_x, x), v_scale(cam->pixel_y, y));
	ray->orient = v_add(ray->orient, cam->img_origin);
	ray->orient = v_normalize(v_subtract(ray->orient, ray->origin));
	ray->hit_time = 999999; //   CHANGE
}

void	raytrace(t_scene *scene, t_ray *ray)
{
	t_list					*obj_ptr;
	static	void (*const	func_ptr[5])(void *, t_ray *) = {
		// rt_cylinder, rt_plane, rt_sphere, rt_square, rt_triangle};
		rt_sphere, rt_sphere, rt_sphere, rt_sphere, rt_sphere};

	obj_ptr = scene->object;
	while (obj_ptr)
	{
		if (*(t_uchar *)(obj_ptr->content) == 2)
			func_ptr[*(t_uchar *)(obj_ptr->content)](obj_ptr->content, ray);
		obj_ptr = obj_ptr->next;
	}
}

t_coord	calc_hit_point(t_ray *ray)
{
	return (v_add(ray->origin, v_scale(ray->orient, ray->hit_time)));
}
