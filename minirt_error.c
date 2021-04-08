/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:40:11 by rkochhan          #+#    #+#             */
/*   Updated: 2021/04/08 09:21:15 by rkochhan         ###   ########.fr       */
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

void	print_scene_error(const char *message, const char *file, size_t line)
{
	static bool	first_error = true;
	char		error_str[128];

	if (first_error == true)
	{
		first_error = false;
		ft_putendl_fd("Error", 2);
	}
	if (file && line)
	{
		ft_strlcpy(error_str, file, sizeof(error_str));
		ft_strlcat(error_str, ", (line ", sizeof(error_str));
		ft_strlcat(error_str, ft_itoa(line), sizeof(error_str));
		ft_strlcat(error_str, "): ", sizeof(error_str));
		ft_strlcat(error_str, message, sizeof(error_str));
	}
	else
		ft_strlcpy(error_str, message, sizeof(error_str));
	ft_putendl_fd(error_str, 2);
}

void	print_system_error(const char *message)
{
	char	error_str[64];

	ft_strlcpy(error_str, "Error\nSystem, ", sizeof(error_str));
	ft_strlcat(error_str, message, sizeof(error_str));
	perror(error_str);
	exit(EXIT_FAILURE);
}
