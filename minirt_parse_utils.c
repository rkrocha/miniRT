/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:14:10 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/10 17:18:58 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	parse_coords(char **line, bool *scene_error, int line_num)
{
	t_coord	position;
	float	coord[3];
	int		i;

	i = 0;
	while (i <= 2)
	{
		*line = ft_strignore(*line, WHITE_SPACES);
		if (!(ft_strchr("+-.", **line) || ft_isdigit(**line)))
		{
			print_scene_error(SCENE_COORD, line_num);
			*scene_error = true;
			break ;
		}
		coord[i] = ft_atof(*line);
		*line = strignore(*line, "+-.0123456789");
		*line = ft_strignore(*line, WHITE_SPACES);
		if (i < 2 && **line == ',')
			(*line)++;
		i++;
	}
	position.x = coord[0];
	position.y = coord[1];
	position.z = coord[2];
	return (position);
}
