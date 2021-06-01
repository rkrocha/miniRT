/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:09:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/06/01 09:59:41 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifndef MINIRT_DEBUG
#  define MINIRT_DEBUG 0
# endif

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include "get_next_line.h"
# include "libft.h"
# include "libvector.h"
# include "minirt_error.h"
# include "minirt_types.h"
# include "mlx.h"

typedef struct s_minilibx
{
	void	*ptr;
	void	*window;
	t_list	*first_cam;
	t_list	*active_cam;
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_minilibx;

/*
** minirt_window.c:
*/
void	check_adjust_window_resolution(t_minilibx *mlx, t_scene *scene);
void	display_manager(t_minilibx *mlx);

/*
** minirt_mlx_utils.c:
*/
int		color_picker(t_uchar red, t_uchar green, t_uchar blue);
void	create_image(t_minilibx *mlx, int width, int height);
void	putpixel_image(t_minilibx *mlx, int x, int y, int color);
void	fill_image(t_minilibx *mlx, t_scene *scene, int color);

/*
** minirt_scene.c:
*/
void	parse_scene(const char *file, t_scene *scene);
void	free_scene(t_scene *scene);

/*
** minirt_parse_elements.c:
*/
void	parse_by_type(char *line, t_scene *scene, bool *scene_error);

/*
** minirt_parse_objects.c:
*/
void	parse_cylinder(char *line, t_list **object, bool *error, int line_num);
void	parse_plane(char *line, t_list **object, bool *error, int line_num);
void	parse_sphere(char *line, t_list **object, bool *error, int line_num);
void	parse_square(char *line, t_list **object, bool *error, int line_num);
void	parse_triangle(char *line, t_list **object, bool *error, int line_num);

/*
** minirt_parse_utils.c:
*/
void	parse_invalid_element(char *line, bool *error, int line_num);
void	parse_light_ratio(float *ratio, char *str, bool *error, int line_num);
void	parse_position(t_coord *position, char *str, bool *error, int line_num);
void	parse_orient(t_coord *orient, char *str, bool *error, int line_num);
void	parse_rgb(int *color, char *str, bool *error, int line_num);

/*
** minirt_debug_elements.c:
*/
void	debug_line(char *line, int line_num);
void	debug_res(char *line, t_scene scene, int line_num);
void	debug_ambl(char *line, t_light ambient, int line_num);
void	debug_camera(char *line, t_camera camera, int line_num);
void	debug_light(char *line, t_light light, int line_num);

/*
** minirt_debug_objects.c:
*/
void	debug_cylinder(char *line, t_cylinder cylinder, int line_num);
void	debug_plane(char *line, t_plane plane, int line_num);
void	debug_sphere(char *line, t_sphere sphere, int line_num);
void	debug_square(char *line, t_square square, int line_num);
void	debug_triangle(char *line, t_triangle triangle, int line_num);

#endif
