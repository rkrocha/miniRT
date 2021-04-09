/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:09:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/09 18:08:29 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_vectors.h"
# include "get_next_line.h"
# include "minirt_error.h"
# include "minirt_types.h"
# include "mlx.h"

/*
** minirt_scene.c:
*/
void	parse_scene(const char *file, t_scene *scene);
void	free_scene(t_scene *scene);

#endif
