/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:57:03 by rkochhan          #+#    #+#             */
/*   Updated: 2021/03/23 18:16:46 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

#include "ft_vectors.h"

typedef int		t_rgb;

typedef struct	s_light
{
	t_coord		position;
	float		brightness;
	t_rgb		color;
}				t_light;

typedef struct	s_scene
{
	int			render_width;
	int			render_height;
	t_light		ambient;
	t_list		*camera;
	t_list		*object;
	t_list		*light;
}				t_scene;

typedef struct	s_camera
{
	t_coord		position;
	t_vector	orientation;
	float		fov;
}				t_camera;

/*
** The following types are to be stored in a common libft linked list, with
** their addresses saved to a void pointer. Therefore they need an "id" as
** first variable, so they can be later recast to their correct types. Each
** type has its own unique id.
*/
typedef struct	s_sphere
{
	t_uchar		id;
	t_coord		position;
	float		diameter;
	t_rgb		color;
}				t_sphere;

typedef struct	s_plane
{
	t_uchar		id;
	t_coord		position;
	t_vector	orientation;
}				t_plane;

typedef struct	s_square
{
	t_uchar		id;
	t_coord		position;
	t_vector	orientation;
	float		side;
	t_rgb		color;
}				t_square;

typedef struct	s_cylinder
{
	t_uchar		id;
	t_coord		position;
	float		diameter;
	float		height;
	t_rgb		color;
}				t_cylinder;

typedef struct	s_triangle
{
	t_uchar		id;
	t_coord		point_a;
	t_coord		point_b;
	t_coord		point_c;
	t_rgb		color;
}				t_triangle;

#endif
