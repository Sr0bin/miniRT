/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:43:09 by jweber            #+#    #+#             */
/*   Updated: 2025/11/03 11:20:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_vectors.h"
# include "minirt.h"

# define WHITE_SPACE " \f\n\r\t\v"

typedef struct s_line
{
	char	*content;
	size_t	line_nbr;
}		t_line;

int		parsing(int argc, char **argv, t_vector *ptr_objects,
			char **ptr_str_err_msg);
int		check_args(int argc, char **argv);
int		get_file_content(char *filename, t_vector *ptr_file_content);
int		fill_obj_content(t_object *ptr_obj_tmp, char **elements,
			char **ptr_str_err_msg);
int		fill_obj_ambient(t_object *ptr_obj_tmp, char **elements,
			char **ptr_str_err_msg);
int		fill_obj_camera(t_object *ptr_obj_tmp, char **elements,
			char **ptr_str_err_msg);
int		fill_obj_light(t_object *ptr_obj_tmp, char **elements,
			char **ptr_str_err_msg);
int		fill_obj_sphere(t_object *ptr_obj_tmp, char **elements,
			char **ptr_str_err_msg);
int		fill_obj_plane(t_object *ptr_obj_tmp, char **elements,
			char **ptr_str_err_msg);
int		fill_obj_cylinder(t_object *ptr_obj_tmp, char **elements,
			char **ptr_str_err_msg);
int		fill_colors(t_rgba *ptr_rgba, const char *str,
			char **ptr_str_err_msg);
int		fill_coordinates(t_point **ptr_to_ptr_coo, const char *coo,
			char **ptr_str_err_msg);
int		fill_direction(t_vec3 **ptr_to_ptr_direction, const char *direction,
			char **ptr_str_err_msg);
void	free_obj_vector(t_vector **ptr_to_ptr_vec, char **ptr_str_err_msg);
int		init_msg_atof_failed(char **ptr_str_err_msg,
			int ret, char *input);
int		init_msg_atoi_failed(char **ptr_str_err_msg,
			int ret, char *input);
int		fail_add_msg(const char *msg, int ret, char **ptr_str_err_msg);

# define MSG_AMBIENT_WRONG_ARGUMENTS "Ambient:\n\
Wrong number of arguments.\n\
Ambient takes 3 arguments separated by spaces.\n\
ex: A\t0.2\t255,255,255\t\n\
1: ambient identifer\n\
2: ambient lighting ratio\n\
3: ambient colors (RGB)\n"

# define MSG_CAMERA_WRONG_ARGUMENTS "Camera:\n\
Wrong number of arguments.\n\
Camera takes 4 arguments separated by spaces.\n\
ex: C\t-50.0,0,20\t0,0,1\t70\n\
1: camera identifer\n\
2: viewpoint coordinates\n\
3: 3D normalized orientation vector\n\
4: FOV: Horizontal field of view in degree\n"

# define MSG_LIGHT_WRONG_ARGUMENTS "Light:\n\
Wrong number of arguments.\n\
Light takes 4 arguments separated by spaces.\n\
ex: L\t-40.0,50.0,0.0\t0.6\t10,0,255\n\
1: light identifer\n\
2: cooridnates of light point\n\
3: light brightness ratio\n\
4: light color (RGB)\n"

# define MSG_SPHERE_WRONG_ARGUMENTS "Sphere:\n\
Wrong number of arguments.\n\
Sphere takes 4 arguments separated by spaces.\n\
ex: sp\t-40.0,50.0,0.0\t0.6\t10,0,255\n\
1: sphere identifer\n\
2: sphere center coordinates\n\
3: sphere diameter\n\
4: sphere colors (RGB)\n"

# define MSG_PLANE_WRONG_ARGUMENTS "Plane:\n\
Wrong number of arguments.\n\
Plane takes 4 arguments separated by spaces.\n\
ex: pl\t0.0,0.0,-10.0\t0.0,1.0,0.0\t0,0,225\n\
1: plane identifer\n\
2: coordinates of a point in the plane\n\
3: 3D normalized vector\n\
4: plan color (RGB)\n"

# define MSG_CYLINDER_WRONG_ARGUMENTS "Cylinder:\n\
Wrong number of arguments.\n\
Cylinder takes 4 arguments separated by spaces.\n\
ex: cy\t50.0,0.0,20.6\t0.0,0.0,1.0\t14.2\t21.42\t10,0,255\n\
1: cylinder identifer\n\
2: 3D normalized vector of axis of cylinder\n\
3: cylinder diameter\n\
4: cylinder height\n\
5: cylinder color (RGB)\n"

# define MSG_COLOR_WRONG_ARGUMENTS "Wrong number of colors.\n\
Colors consists of 3 integer, between 0 and 255, separated by \
exactly one comma, of format RGB.\n\
ex: 10,0,255\n"

# define MSG_COORDINATES_WRONG_ARGUMENTS "wrong number of coordinates.\n\
Coordinates consists of 3 decimal values separated by exactly one comma.\n\
ex: 10,0,255\n"

# define MSG_DIRECTION_WRONG_ARGUMENTS "wrong number of direction.\n\
direction consists of 3 decimal values separated by exactly one comma, \
its value must be normalized.\n\
ex: 10,0,255\n"

#endif // !PARSING_H
