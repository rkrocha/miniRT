/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:14:10 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/14 21:39:08 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	get_next_float(float *number, char **line)
{
	*line = ft_strsearch(*line, "+-.0123456789");
	if (!(*line))
		return (false);
	*number = ft_atof(*line);
	*line = ft_strignore(*line, "+-.0123456789");
	return (true);
}

bool	get_next_int(int *number, char **line)
{
	*line = ft_strsearch(*line, "+-.0123456789");
	if (!(*line))
		return (false);
	*number = ft_atoi(*line);
	*line = ft_strignore(*line, "+-.0123456789");
	return (true);
}

/*
** If a line that does not match any expected type identifier contains only
** white spaces, then it is ignored. If any other unexpected character is
** found, then both the line and the scene file are considered invalid.
*/
void	parse_invalid_element(char *line, bool *error, int line_num)
{
	if (!ft_strignore(line, WHITE_SPACES))
		return ;
	print_scene_error(SCENE_INVALID_TYPE, line_num);
	*error = true;
}

bool	parse_light_ratio(float *ratio, char **line, int line_num)
{
	if (!get_next_float(ratio, line)
		|| *ratio < 0.0 || *ratio > 1.0)
	{
		print_scene_error(SCENE_LIGHT, line_num);
		return (false);
	}
	return (true);
}

bool	parse_rgb(int *color, char **line, int line_num)
{
	char	*end_ptr;
	bool	rgb_error;
	int		rgb[3];
	int		i;

	i = 0;
	rgb_error = false;
	*line = ft_strignore(*line, WHITE_SPACES);
	end_ptr = ft_strignore(*line, "+,0123456789");
	while (i < 3)
	{
		if (!get_next_int(&rgb[i], line) || (end_ptr && *line > end_ptr)
			|| rgb[i] < 0 || rgb[i] > 255)
		{
			if (!rgb_error)
				print_scene_error(SCENE_RGB, line_num);
			rgb_error = true;
		}
		i++;
	}
	*color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	if (rgb_error)
		return (false);
	return (true);
}

bool	parse_position(t_coord *position, char **line, int line_num)
{
	char	*end_ptr;
	bool	pos_error;
	float	coord[3];
	int		i;

	i = 0;
	pos_error = false;
	*line = ft_strignore(*line + 1, WHITE_SPACES);
	end_ptr = ft_strignore(*line, "+-.,0123456789");
	while (i < 3)
	{
		if (!get_next_float(&coord[i], line) || (end_ptr && *line > end_ptr))
		{
			if (!pos_error)
				print_scene_error(SCENE_COORD, line_num);
			pos_error = true;
		}
		i++;
	}
	position->x = coord[0];
	position->y = coord[1];
	position->z = coord[2];
	if (pos_error)
		return (false);
	return (true);
}

bool	parse_orientation(t_coord *orient, char **line, int line_num)
{
	char	*end_ptr;
	bool	orient_error;
	float	coord[3];
	int		i;

	i = 0;
	orient_error = false;
	*line = ft_strignore(*line, WHITE_SPACES);
	end_ptr = ft_strignore(*line, "+-.,0123456789");
	while (i < 3)
	{
		if (!get_next_float(&coord[i], line) || (end_ptr && *line > end_ptr))
		{
			if (!orient_error)
				print_scene_error(SCENE_ORIENT, line_num);
			orient_error = true;
		}
		i++;
	}
	orient->x = coord[0];
	orient->y = coord[1];
	orient->z = coord[2];
	if (orient_error)
		return (false);
	return (true);
}
// REWRITE SIMILAR FUNCTIONS?
