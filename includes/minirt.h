/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:00 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 13:46:52 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "ft_vectors.h"
# include "vec3.h"
# include "point3.h"
# include <stdint.h>

# undef SUCCESS
# undef FAILURE

# define AXIS_THREE 4
# define AXIS_FOUR 5
// # define BACKGROUND_COLOR 0xecb5f5 // Purple Pastel
# define BACKGROUND_COLOR 0x000000
# define DEFAULT_LIGHT_COLOR 0xffffff

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
	FAILURE_PARSE_WRONG_NB_AMBIENT,
	FAILURE_PARSE_WRONG_NB_LIGHT,
	FAILURE_PARSE_WRONG_NB_CAMERA,
	FAILURE_MLX,
};

enum e_bool
{
	FALSE = 0,
	TRUE = 1,
};

typedef struct s_rgba
{
	uint8_t	blue;
	uint8_t	green;
	uint8_t	red;
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
typedef enum e_obj_type
{
	OBJ_AMBIENT = 0,
	OBJ_CAMERA = 1,
	OBJ_LIGHT = 2,
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
}	t_obj_type;

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
	t_vec3	direction;
	t_color	color;
	double	a;
	double	b;
	double	c;
	double	d;
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

typedef struct s_object
{
	t_obj_type		type;
	t_point3		coordinates;
	t_object_attr	object_attr;
}		t_object;

typedef struct s_scene
{
	t_object	ambient_light;
	t_object	camera;
	t_vector	lights_arr;
	t_vector	objects;
}	t_scene;

#endif // !PARSING_H
