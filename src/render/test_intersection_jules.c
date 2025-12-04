/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:24:27 by jweber            #+#    #+#             */
/*   Updated: 2025/12/05 00:08:17 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "point3.h"
#include "ray.h"
#include "vec3.h"
#include "render.h"
#include "intersection.h"
#include <math.h>
#include <stdio.h>

void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_scene *ptr_scene);

int	test_intersection_jules(t_ray *ray_array, size_t nb_rays,
		t_color *pixel_array, t_scene *ptr_scene)
{
	size_t	x_i;

	x_i = 0;
	while (x_i < nb_rays)
	{
		set_pixel_color(ray_array[x_i], pixel_array + x_i, ptr_scene);
		x_i++;
	}
	return (0);
}

void	update_closest_intersect(t_intersect *intersect_data, t_intersect *intersect_data_tmp)
{
	if (intersect_data->ptr_obj == NULL)
		*intersect_data = *intersect_data_tmp;
	else
		if (intersect_data_tmp->distance < intersect_data->distance)
			*intersect_data = *intersect_data_tmp;
}

int		update_intersect_object(t_ray ray, t_object	*obj, t_intersect *intersect_data)
{
	t_intersect	intersect_data_tmp;
	int		ret;

	intersect_data_tmp.ptr_obj = obj;
	if (obj->type == OBJ_SPHERE)
	{
		ret = check_intersect_sphere(ray, *obj, &intersect_data_tmp);
		if (ret == TRUE)
		{
			update_closest_intersect(intersect_data, &intersect_data_tmp);
			return (TRUE);
		}
	}
	else if (obj->type == OBJ_PLANE)
	{
		ret = check_intersect_plane(ray, *obj, &intersect_data_tmp);
		if (ret == TRUE)
		{
			update_closest_intersect(intersect_data, &intersect_data_tmp);
			return (TRUE);
		}
	}
	return (FALSE);
}

static t_color	*object_color(t_object	*obj)
{
	if (obj->type == OBJ_SPHERE)
		return (&obj->object_attr.sphere.color);
	if (obj->type == OBJ_PLANE)
		return (&obj->object_attr.plane.color);
	if (obj->type == OBJ_CYLINDER)
		return (&obj->object_attr.cylinder.color);
	if (obj->type == OBJ_LIGHT)
		return (&obj->object_attr.light.color);
	return (NULL);
}

t_color	multiply_color_coeff(t_color first, t_color second, double coeff)
{
	t_color	temp;
	t_rgba	temp_rgba;
	t_rgba	first_rgba;
	t_rgba	second_rgba;

	temp = (t_color) {0};
	first_rgba = first.rgba;
	second_rgba = second.rgba;
	temp_rgba.red = (uint8_t) ((sqrt(first_rgba.red * second_rgba.red)) * coeff);
	temp_rgba.blue = (uint8_t) ((sqrt(first_rgba.blue * second_rgba.blue)) * coeff);
	temp_rgba.green = (uint8_t) ((sqrt(first_rgba.green * second_rgba.green)) * coeff);
	// c'est lequel le bon??
	// temp_rgba.red = (uint8_t) ((sqrt(obj_rgba.red * ambient_rgba.red) / 2) * coeff);
	// temp_rgba.blue = (uint8_t) (((obj_rgba.blue * ambient_rgba.blue) / 2 )  * coeff);
	// temp_rgba.green = (uint8_t) (((obj_rgba.green * ambient_rgba.green) / 2) *  coeff);
	temp.rgba = temp_rgba;
	return (temp);

}
t_color	object_ambient_color(t_object *obj, t_scene scene)
{
	t_color	ambient_color;
	double	coeff;

	ambient_color = scene.ambient_light.object_attr.ambient.color;
	coeff = scene.ambient_light.object_attr.ambient.ratio;
	return (multiply_color_coeff(*object_color(obj), ambient_color, coeff));
}

t_color	color_add(t_color a, t_color b)
{
	t_color	temp;

	temp = (t_color) {0};
	if (a.rgba.red + b.rgba.red <= UINT8_MAX)
		temp.rgba.red = a.rgba.red + b.rgba.red;
	else
		temp.rgba.red = UINT8_MAX;
	if (a.rgba.blue + b.rgba.blue <= UINT8_MAX)
		temp.rgba.blue = a.rgba.blue + b.rgba.blue;
	else
		temp.rgba.blue = UINT8_MAX;
	if (a.rgba.green + b.rgba.green <= UINT8_MAX)
		temp.rgba.green = a.rgba.green + b.rgba.green;
	else
		temp.rgba.green = UINT8_MAX;
	return (temp);
}

static t_vec3	sphere_normal(t_intersect *intersect_data, t_object *sphere)
{
	t_vec3	normal;

	// normal = vect3_from_point3(intersect_data->intersect_point, sphere->coordinates);
	normal = vect3_from_point3( sphere->coordinates, intersect_data->intersect_point);
	normalize_vec3(&normal);
	return (normal);
}
static double	coeff_direct_light(t_intersect	*intersect_data, t_object *light)
{
	double	temp;
	t_vec3	normal;
	t_vec3	light_dir;

	if(intersect_data->ptr_obj->type != OBJ_SPHERE)
		return (0);
	normal = sphere_normal(intersect_data, intersect_data->ptr_obj);
	light_dir = vect3_from_point3(intersect_data->intersect_point, light->coordinates);
	temp = dot_product3(normal, light_dir); 
	if (temp < 0)
		return (0);
	temp /= vec3_norm(normal) * vec3_norm(light_dir);
	return (temp);
}
t_color	object_direct_light(t_intersect	*intersect_data, t_scene *scene, t_object *light)
{
	double	coeff;
	t_ray	temp_ray;
	t_intersect	inter;

	inter = (t_intersect) {0};
	temp_ray.ptr_origin = &intersect_data->intersect_point;
	temp_ray.direction = vect3_from_point3(intersect_data->intersect_point, light->coordinates);
	if (update_intersect_all_object(temp_ray, scene->objects.data, scene->objects.size, &inter) == FALSE)
	{
		coeff = coeff_direct_light(intersect_data, light); 
		return (multiply_color_coeff(*object_color(intersect_data->ptr_obj), light->object_attr.light.color, coeff));
	}
	return ((t_color) {0});
}

t_color	object_sum_direct_light(t_intersect *intersect_data, t_scene *scene)
{
	t_color		temp;
	t_object	*crnt_light;
	size_t	i;


	i = 0;
	temp = (t_color) {0};
	while (i < scene->lights_arr.size)
	{
		crnt_light = &((t_object *)scene->lights_arr.data)[i];
		temp = color_add(temp, object_direct_light(intersect_data, scene, crnt_light));
		i++;
	}
	return (temp);

}

void	update_intersect_color(t_intersect	*intersect_data, t_scene *ptr_scene)
{
	//belek : si il n'y a pas de hit, mettre la backround color
	if (intersect_data->ptr_obj != NULL)
	{
		intersect_data->crnt_color = object_ambient_color(intersect_data->ptr_obj, *ptr_scene);
		intersect_data->crnt_color = color_add(intersect_data->crnt_color, 
				object_sum_direct_light(intersect_data, ptr_scene));
		// if (intersect_data->ptr_obj->type == OBJ_SPHERE)
		// 	intersect_data->crnt_color = intersect_data->ptr_obj->object_attr.sphere.color;
		// if (intersect_data->ptr_obj->type == OBJ_PLANE)
		// 	intersect_data->crnt_color = intersect_data->ptr_obj->object_attr.plane.color;
	}

}

int	update_intersect_all_object(t_ray ray, t_object *obj_array, 
	size_t count, t_intersect *intersect_data)
{
	size_t		obj_i;
	int	hit;

	// intersect_data.ptr_obj = NULL;
	obj_i = 0;
	hit = 0;
	while (obj_i < count)
	{
		hit |= update_intersect_object(ray, &obj_array[obj_i], intersect_data);
		obj_i++;
	}
	return (hit);

}

void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_scene *ptr_scene)
{
	t_object	*obj_array;
	t_intersect	intersect_data;

	obj_array = ptr_scene->objects.data;
	intersect_data = (t_intersect) {0};
	intersect_data.crnt_color.color = 0;
	update_intersect_all_object(ray, obj_array, ptr_scene->objects.size, &intersect_data);
	update_intersect_color(&intersect_data, ptr_scene);
	ptr_pixel->color = intersect_data.crnt_color.color;
	return ;
}
