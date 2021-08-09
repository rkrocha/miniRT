/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_basic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:29:39 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/09 02:00:20 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_coord	v_create(float x, float y, float z)
{
	t_coord	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_coord	v_add(t_coord v, t_coord u)
{
	return (v_create(v.x + u.x, v.y + u.y, v.z + u.z));
}

t_coord	v_sub(t_coord v, t_coord u)
{
	return (v_create(v.x - u.x, v.y - u.y, v.z - u.z));
}
