/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 08:09:28 by rkochhan          #+#    #+#             */
/*   Updated: 2021/08/08 16:25:11 by rkochhan         ###   ########.fr       */
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
	t_list	*active_cam;
	t_scene	*scene;
}	t_minilibx;


/*
** minirt.c:
*/
void	render_image(t_scene *scene, t_camera *cam);

/*
** minirt_raytracing.c:
*/
void	calc_aux_geometry(t_camera *cam, int res_x, int res_y);
t_coord	calc_hit_point(t_ray *ray);
void	calc_ray(t_ray *ray, t_camera *cam, float x, float y);
void	raytrace(t_scene *scene, t_ray *ray);

/*
** minirt_raytracing_collision.c:
*/
bool	rt_plane(void *object, t_ray *ray);
bool	rt_sphere(void *object, t_ray *ray);

/*
** minirt_raytracing_light.c:
*/
void	calc_light(t_ray *ray, t_ray *shade, t_light ambi, t_light light);

/*
** minirt_raytracing_extra.c:
*/
void	bhaskara(float a, float b, float c, float *root);
bool	rt_square(void *object, t_ray *ray);
bool	rt_triangle(void *object, t_ray *ray);

/*
** minirt_colors.c:
*/
int		c_add(int color_a, int color_b);
int		c_product(int c1, int c2);
int		c_scale(int color, float coef);

/*
** minirt_display.c:
*/
void	check_adjust_window_resolution(t_minilibx *mlx, t_scene *scene);
void	display_manager(t_minilibx *mlx);

/*
** minirt_mlx_hook_functions.c:
*/
int		close_window(t_minilibx *mlx);
int		keyboard_input(int keycode, t_minilibx *mlx);
int		refresh_display(t_minilibx *mlx);

/*
** minirt_mlx_utils.c:
*/
void	create_image(t_minilibx *mlx);
void	lst_image_destroy(t_minilibx *mlx, t_list *lst);
int		color_picker(t_uchar red, t_uchar green, t_uchar blue);
void	putpixel_image(t_image *image, int x, int y, int color);
void	fill_image(t_minilibx *mlx, int color);

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
