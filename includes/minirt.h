/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:42:52 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 16:10:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

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
	FAILURE_PARSE_WRONG_OBJ_TYPE,
};

# include "ft_vectors.h"
# include <stdint.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}			t_point;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

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

enum	e_obj_type
{
	OBJ_AMBIENT,
	OBJ_CAMERA,
	OBJ_LIGHT,
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
	t_vec3	direction;
	double	fov;
}			t_camera;

typedef struct s_light
{
	t_vec3	direction;
	double	light_brightness;
	t_color	color;
}			t_light;

typedef struct s_sphere
{
	double	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	direction;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	direction;
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
	t_point			coordinates;
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
