/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:14:10 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/14 14:58:55 by rkochhan         ###   ########.fr       */
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
			print_scene_error(SCENE_RGB, line_num);
			rgb_error = true;
			break ;
		}
		i++;
	}
	*color = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	if (rgb_error)
		return (false);
	return (true);
}
