/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:57:03 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/19 15:28:37 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

# define TYPE_CYLINDER	1
# define TYPE_PLANE		2
# define TYPE_SPHERE	3
# define TYPE_SQUARE	4
# define TYPE_TRIANGLE	5

# include "ft_vectors.h"

typedef struct s_camera
{
	t_coord		position;
	t_coord		orient;
	float		fov;
}	t_camera;

typedef struct s_light
{
	t_coord		position;
	float		ratio;
	int			color;
}	t_light;

typedef struct s_scene
{
	int			render_width;
	int			render_height;
	t_light		ambient;
	t_list		*camera;
	t_list		*light;
	t_list		*object;
	bool		defined_resolution;
	bool		defined_ambient_light;
}	t_scene;

/*
** The following types are to be stored in a common libft linked list, with
** their addresses saved to a void pointer. Therefore they need an "id" as
** first variable, so they can be later recast to their correct types. Each
** type has its own unique id as seen in the defines at the top of this file.
*/
typedef struct s_cylinder
{
	t_uchar		id;
	t_coord		position;
	t_coord		orient;
	float		diameter;
	float		height;
	int			color;
}	t_cylinder;

typedef struct s_plane
{
	t_uchar		id;
	t_coord		position;
	t_coord		orient;
	int			color;
}	t_plane;

typedef struct s_sphere
{
	t_uchar		id;
	t_coord		position;
	float		diameter;
	int			color;
}	t_sphere;

typedef struct s_square
{
	t_uchar		id;
	t_coord		position;
	t_coord		orient;
	float		side;
	int			color;
}	t_square;

typedef struct s_triangle
{
	t_uchar		id;
	t_coord		point_a;
	t_coord		point_b;
	t_coord		point_c;
	int			color;
}	t_triangle;

#endif
