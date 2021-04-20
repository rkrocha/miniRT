/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:14:10 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/20 11:43:48 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** If a line that does not match any expected type identifier contains only
** white spaces, then it is ignored. If any other unexpected character is
** found, then both the line and the scene file are considered invalid.
*/
void	parse_invalid_element(char *line, bool *error, int line_num)
{
	if (!ft_strignore(line, BLANK_SPACES))
		return ;
	print_scene_error(SCENE_INVALID_TYPE, line_num);
	*error = true;
}

void	parse_light_ratio(float *ratio, char *str, bool *error, int line_num)
{
	*ratio = ft_atof(str);
	if (*ratio < 0 || *ratio > 1)
	{
		print_scene_error(SCENE_LIGHT, line_num);
		*error = true;
	}
}

void	parse_rgb(int *color, char *str, bool *error, int line_num)
{
	int		rgb[3];
	char	**rgb_split;
	short	i;

	rgb_split = ft_split(str, ',');
	i = 0;
	while (i < 3)
	{
		if (rgb_split[i])
			rgb[i] = ft_atoi(rgb_split[i]);
		else if (!rgb_split[i] || rgb[i] < 0 || rgb[i] > 255)
		{
			print_scene_error(SCENE_RGB, line_num);
			*error = true;
			if (!rgb_split[i])
				break ;
		}
		i++;
	}
	ft_split_free(&rgb_split);
	*color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	parse_position(t_coord *position, char *str, bool *error, int line_num)
{
	float	coord[3];
	char	**coord_split;
	short	i;

	coord_split = ft_split(str, ',');
	i = 0;
	while (i < 3)
	{
		if (coord_split[i])
			coord[i] = ft_atof(coord_split[i]);
		else
		{
			print_scene_error(SCENE_COORD, line_num);
			*error = true;
			break ;
		}
		i++;
	}
	ft_split_free(&coord_split);
	*position = v_create(coord[0], coord[1], coord[2]);
}

void	parse_orient(t_coord *orient, char *str, bool *error, int line_num)
{
	float	coord[3];
	char	**coord_split;
	short	i;

	coord_split = ft_split(str, ',');
	i = 0;
	while (i < 3)
	{
		if (coord_split[i])
			coord[i] = ft_atof(coord_split[i]);
		else if (!coord_split[i] || coord[i] < -1 || coord[i] > 1)
		{
			print_scene_error(SCENE_ORIENT, line_num);
			*error = true;
			break ;
		}
		i++;
	}
	ft_split_free(&coord_split);
	*orient = v_create(coord[0], coord[1], coord[2]);
	if (!v_is_normal(*orient) && v_module(*orient) != 0)
		*orient = v_normalize(*orient);
}
