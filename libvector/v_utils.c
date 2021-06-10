/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:05:09 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/10 11:44:57 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

float	v_module(t_coord v)
{
	return (sqrt(v_dot(v, v)));
}

bool	v_is_normal(t_coord v)
{
	if (v_module(v) == 1)
		return (true);
	return (false);
}

t_coord	v_normalize(t_coord v)
{
	float	module;

	module = v_module(v);
	return (v_create(v.x / module, v.y / module, v.z / module));
}
