/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:57:03 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/08 19:15:51 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

# define FLOAT_EPSILON 1e-3

# define TYPE_CYLINDER	0
# define TYPE_PLANE		1
# define TYPE_SPHERE	2
# define TYPE_SQUARE	3
# define TYPE_TRIANGLE	4

# include "libvector.h"

typedef struct	s_ray
{
	t_coord	origin;
	t_coord	orient;
	float	hit_time;
	int		hit_color;
	t_coord	hit_point;
	t_coord	hit_normal;
	void	*hit_obj;
}	t_ray;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	bool	is_rendered;
}	t_image;

typedef struct s_camera
{
	t_coord		position;
	t_coord		orient;
	float		fov;
	t_coord		img_origin;
	t_coord		pixel_x;
	t_coord		pixel_y;
	t_image		image;
}	t_camera;

typedef struct s_light
{
	t_coord		position;
	float		ratio;
	int			color;
}	t_light;

typedef struct s_scene
{
	int			res_x;
	int			res_y;
	t_light		ambient;
	t_list		*camera;
	t_list		*light;
	t_list		*object;
	bool		defined_resolution;
	bool		defined_amblight;
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
