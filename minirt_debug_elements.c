/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_debug_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:57:10 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/14 15:03:20 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt_debug_line(char *line, int line_num)
{
	char	str[128];
	char	*line_num_str;

	ft_strlcpy(str, "Scene line ", sizeof(str));
	ft_strlcat(str, line_num_str = ft_itoa(line_num), sizeof(str));
	free(line_num_str);
	ft_strlcat(str, " is: ", sizeof(str));
	ft_putstr_fd(str, 2);
	while (*line)
	{
		if (ft_isspace(*line))
		{
			ft_putchar_fd(' ', 2);
			line = ft_strignore(line, WHITE_SPACES);
		}
		else
		{
			ft_putchar_fd(*line, 2);
			line++;
		}
	}
	ft_putchar_fd('\n', 2);
}

void	minirt_debug_res(char *line, t_scene scene, int line_num)
{
	minirt_debug_line(line, line_num);
	printf("Resolution set: %dx%d\n\n",
		scene.render_width, scene.render_height);
}

void	minirt_debug_ambl(char *line, t_light ambient, int line_num)
{
	minirt_debug_line(line, line_num);
	printf("Info parsed: light ratio = %f | RGB = %#.8x\n\n",
		ambient.ratio, ambient.color);
}
