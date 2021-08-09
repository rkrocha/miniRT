/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:44:55 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 02:00:58 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H

# include <math.h>
# include <stdbool.h>

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
}	t_coord;

/*
** v_basic.c:
*/
t_coord	v_create(float x, float y, float z);
t_coord	v_sub(t_coord v, t_coord u);
t_coord	v_add(t_coord v, t_coord u);

/*
** v_products.c:
*/
t_coord	v_scale(t_coord v, float scale);
t_coord	v_cross(t_coord v, t_coord u);
float	v_dot(t_coord v, t_coord u);

/*
** v_utils.c:
*/
float	v_module(t_coord v);
bool	v_is_normal(t_coord v);
t_coord	v_normalize(t_coord v);

#endif
