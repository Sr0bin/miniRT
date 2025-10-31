/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:00 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 16:47:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "ft_vectors.h"
# include "vector.h"
# include "point.h"
# include <stdint.h>

# undef SUCCESS
# undef FAILURE

enum e_status
{
	SUCCESS = 0,
	FAILURE = 1,
	FAILURE_ARGS_WRONG_NUMBER,
	FAILURE_ARGS_MAP_NAME_TOO_LONG,
	FAILURE_ARGS_BAD_MAP_NAME,
	FAILURE_OPEN,
	FAILURE_MALLOC,
	FAILURE_READ,
	FAILURE_PARSE_PERSONNALIZED,
	FAILURE_PARSE_EMPTY_LINE,
	FAILURE_PARSE_WRONG_OBJ_IDENTIFIER,
	FAILURE_PARSE_AMBIENT_WRONG_OBJ_NB_OF_INFO,
	FAILURE_PARSE_CAMERA_WRONG_OBJ_NB_OF_INFO,
	FAILURE_PARSE_LIGHT_WRONG_OBJ_NB_OF_INFO,
	FAILURE_PARSE_SPHERE_WRONG_OBJ_NB_OF_INFO,
	FAILURE_PARSE_PLANE_WRONG_OBJ_NB_OF_INFO,
	FAILURE_PARSE_CYLINDER_WRONG_OBJ_NB_OF_INFO,
	FAILURE_PARSE_COLOR_WRONG_FORMAT,
	FAILURE_PARSE_COLOR_ATOI_FAILED,
	FAILURE_PARSE_COLOR_WRONG_VALUE,
	FAILURE_PARSE_COO_WRONG_FORMAT,
	FAILURE_PARSE_COO_ATOF_FAILED,
	FAILURE_PARSE_SINGLE_ATOF_FAILED,
	FAILURE_PARSE_SINGLE_WRONG_VALUE,
	FAILURE_PARSE_DIRECTION_WRONG_FORMAT,
	FAILURE_PARSE_DIRECTION_ATOF_FAIL,
	FAILURE_PARSE_DIRECTION_WRONG_VALUE,
};

enum e_bool
{
	FALSE = 0,
	TRUE = 1,
};

typedef struct s_rgba
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;
}	t_rgba;

typedef union u_color
{
	int		color;
	t_rgba	rgba;
}	t_color;

/*	ambian, camera, light
 *	are posistionned 0, 1, 2 to 
 *	allow, when object array is sorted
 *	to have them first place to check
 *	for the correct number of each type
 *	(only one allowed for each in mandatory part)
*/
enum	e_obj_type
{
	OBJ_AMBIENT = 0,
	OBJ_CAMERA = 1,
	OBJ_LIGHT = 2,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
};

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}			t_ambient;

typedef struct s_camera
{
	t_vec3	*ptr_direction;
	double	fov;
}			t_camera;

typedef struct s_light
{
	double	brightness;
	t_color	color;
}			t_light;

typedef struct s_sphere
{
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	*ptr_direction;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	*ptr_direction;
	double	diameter;
	double	height;
	t_color	color;
}	t_cylinder;

typedef union u_object_attr
{
	t_camera	camera;
	t_light		light;
	t_ambient	ambient;
	t_plane		plane;
	t_sphere	sphere;
	t_cylinder	cylinder;
}	t_object_attr;

typedef	struct s_object
{
	int				type;
	t_point			*ptr_coordinates;
	t_object_attr	object_attr;
}			t_object;

typedef struct s_tmp_struct
{
	t_vector	all;
	t_vector	ambiant_lightings_arr;
	t_vector	cameras_arr;
	t_vector	lights_arr;
	t_vector	spheres_arr;
	t_vector	planes_arr;
	t_vector	cylinder_arr;
}	t_tmp_struct;

#endif // !PARSING_H
