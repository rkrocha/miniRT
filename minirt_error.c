/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:40:11 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/10 10:39:17 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*malloc_check(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_system_error(SYSTEM_MALLOC);
	return (ptr);
}

void	print_minirt_usage(void)
{
	ft_putendl_fd("Usage is:\n./miniRT scene_file.rt\n", 2);
	ft_putendl_fd("or:\n./miniRT scene_file.rt --save", 2);
}

void	print_scene_error(const char *message, size_t line)
{
	static bool	first_error = true;
	char		error_str[128];
	char		*line_str;

	if (first_error)
	{
		first_error = false;
		ft_putendl_fd("\033[1;31mError\033[0m", 2);
	}
	if (line)
	{
		ft_strlcpy(error_str, "Scene line ", sizeof(error_str));
		ft_strlcat(error_str, line_str = ft_itoa(line), sizeof(error_str));
		ft_strlcat(error_str, ": ", sizeof(error_str));
		ft_strlcat(error_str, message, sizeof(error_str));
		free(line_str);
	}
	else
		ft_strlcpy(error_str, message, sizeof(error_str));
	ft_putendl_fd(error_str, 2);
}

void	print_system_error(const char *message)
{
	char	error_str[64];

	ft_strlcpy(error_str, "\033[1;31mError\033[0m\n", sizeof(error_str));
	ft_strlcat(error_str, "System, ", sizeof(error_str));
	ft_strlcat(error_str, message, sizeof(error_str));
	perror(error_str);
}
