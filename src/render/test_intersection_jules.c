/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:24:27 by jweber            #+#    #+#             */
/*   Updated: 2025/12/05 16:16:38 by rorollin         ###   ########.fr       */
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

t_color	object_ambient_color(t_object *obj, t_scene scene)
{
	t_color	ambient_color;
	double	coeff;

	ambient_color = scene.ambient_light.object_attr.ambient.color;
	coeff = scene.ambient_light.object_attr.ambient.ratio;
	return (multiply_color_coeff(*object_color(obj), ambient_color, coeff));
}


static double	coeff_direct_light(t_intersect	*intersect_data, t_object *light)
{
	double	temp;
	t_vec3	normal;
	t_vec3	light_dir;

	normal = intersect_normal(intersect_data);
	// light_dir = vect3_from_point3(light->coordinates, intersect_data->intersect_point);
	light_dir = vect3_from_point3(intersect_data->intersect_point, light->coordinates);
	temp = dot_product3(normal, light_dir); 
	temp /= vec3_norm(normal) * vec3_norm(light_dir);
	if (temp < 0)
		return (0);
	return (temp*light->object_attr.light.brightness);
}

t_color	object_direct_light(t_intersect	*intersect_data, t_scene *scene, t_object *light)
{
	double	coeff;
	t_ray	temp_ray;
	t_vec3	light_dir;
	t_point3	offset_point;
	t_intersect	inter;

	inter = (t_intersect) {0};
	offset_point = offset_point3(intersect_data->intersect_point,
		vec3_scale(intersect_normal(intersect_data), 0.001));
	temp_ray.ptr_origin = &offset_point;
	// offset_intersect_point(intersect_data);
	light_dir = vect3_from_point3(offset_point, light->coordinates);
	temp_ray.direction = light_dir;
	normalize_vec3(&temp_ray.direction);
	//todo: check that it returns FALSE when it should
	update_intersect_all_object(temp_ray, scene->objects.data, scene->objects.size, &inter);
	if (inter.ptr_obj != NULL && inter.distance < vec3_norm(light_dir))
		return ((t_color) {0});
	coeff = coeff_direct_light(intersect_data, light); 
	// coeff = 1;
	// return (*object_color(light));
	return (multiply_color_coeff(*object_color(intersect_data->ptr_obj), light->object_attr.light.color, coeff));
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
