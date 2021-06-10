/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_products.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:13:05 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/10 11:45:15 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_coord	v_scale(t_coord v, float scale)
{
	return (v_create(v.x * scale, v.y * scale, v.z * scale));
}

/*
** Also known as scalar product.
** If the dot product of two vectors is zero, then said vectors are orthogonal.
*/
float	v_dot(t_coord v, t_coord u)
{
	return ((v.x * u.x) + (v.y * u.y) + (v.z * u.z));
}

/*
** Also known as vector product.
** The cross product of two vectors results in third a vector orthogonal
** to the first two.
*/
t_coord	v_cross(t_coord v, t_coord u)
{
	return (v_create((v.y * u.z) - (v.z * u.y),
			(v.z * u.x) - (v.x * u.z),
			(v.x * u.y) - (v.y * u.x)));
}
