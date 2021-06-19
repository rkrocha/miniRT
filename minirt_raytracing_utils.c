/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_raytracing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:36:56 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/19 10:31:11 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	bhaskara(float a, float b, float c, float *root)
{
	float	sqrt_part;

	sqrt_part = sqrt(b * b - 4 * a * c);
	root[0] = (-b - sqrt_part) / (2 * a);
	root[1] = (-b + sqrt_part) / (2 * a);
}

void	arrange_valid_root(float *root)
{
	float	temp;

	if (root[1] < root[0] && root[1] >= 0)
	{
		temp = root[0];
		root[0] = root[1];
		root[1] = temp;
	}
}

// static int	sq_intersection_II(t_sq *sq, t_ray *ray, double t)
// {
// 	t_mat	mat;
// 	t_tpl	hit;
// 	t_tpl	vec;

// 	hit = sum_vec(ray->orig, mult_vec(ray->dir, t));
// 	hit = sub_vec(hit, sq->orig);
// 	if (sq->norm.y == 1 || sq->norm.y == -1)
// 		mat.c1 = create_vec(1, 0, 0);
// 	else
// 		mat.c1 = cross_vec(create_vec(0, 1, 0), sq->norm);
// 	norm_vec(&mat.c1);
// 	mat.c2 = cross_vec(sq->norm, mat.c1);
// 	mat.c3 = sq->norm;
// 	mat = mat_invert(mat);
// 	vec = mat_dot_prod(mat, hit);
// 	if (fabs(vec.x) <= (sq->side / 2) && fabs(vec.y) <= (sq->side / 2))
// 		return (1);
// 	return (0);
// }

// t_vet	vet_mat_dot(t_mat mat, t_vet vet)
// {
// 	t_vet	v1;

// 	v1.x = mat.c1.x * vet.x + mat.c2.x * vet.y + mat.c3.x * vet.z;
// 	v1.y = mat.c1.y * vet.x + mat.c2.y * vet.y + mat.c3.y * vet.z;
// 	v1.z = mat.c1.z * vet.x + mat.c2.z * vet.y + mat.c3.z * vet.z;
// 	return (v1);
// }
// c1 = u
// c2 = v
// c3 = n
// vet = hit_point


bool	point_in_square(t_ray *ray, t_square *sq, float time)
{
	t_coord	n;
	t_coord	u;
	t_coord	v;
	t_coord	hit;
	t_coord	result;

	hit = v_add(ray->origin, v_scale(ray->orient, time));
	hit = v_subtract(hit, sq->position);
	if (sq->orient.y == 1 || sq->orient.y == -1)
		u = v_create(-1, 0, 0);
	else
		u = v_cross(v_create(0, -1, 0), sq->orient);
	v = v_cross(sq->orient, u);
	n = sq->orient;
	result.x = u.x * hit.x + v.x * hit.y + n.x * hit.z;
	result.y = u.y * hit.x + v.y * hit.y + n.y * hit.z;
	result.z = u.z * hit.x + v.z * hit.y + n.z * hit.z;
	if (fabs(result.x) <= (sq->side / 2) && fabs(result.y) <= (sq->side / 2))
		return (true);
	return (false);
}
