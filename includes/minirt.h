/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:09:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/08 09:13:29 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "ft_vectors.h"
# include "get_next_line.h"
# include "minirt_error.h"
# include "minirt_types.h"
# include "mlx.h"

/*
** minirt_scene.c:
*/
bool	read_scene(const char *file, t_scene *scene);

#endif
