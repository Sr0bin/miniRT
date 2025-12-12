/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:24:27 by jweber            #+#    #+#             */
/*   Updated: 2025/12/11 20:48:51 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "point3.h"
#include "ray.h"
#include "vec3.h"
#include "render.h"
#include "intersection.h"
#include "object.h"
#include "color.h"
#include <math.h>
#include <stdio.h>

void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_scene *ptr_scene);

int	fill_screen(t_ray *ray_array, size_t nb_rays,
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

t_color	object_single_light(t_intersect	*ptr_intersect, t_scene *ptr_scene, t_object *light)
{
	double		coeff;
	t_ray		temp_ray;
	t_vec3		light_dir;
	t_point3	offset_point;
	t_intersect	inter;
	t_color		direct_light;

	inter = (t_intersect) {0};
	offset_point = offset_point3(ptr_intersect->intersect_point,
		vec3_scale(intersect_normal(ptr_intersect), 0.00000000001));
	temp_ray.ptr_origin = &offset_point;
	light_dir = vect3_from_point3(offset_point, light->coordinates);
	temp_ray.direction = light_dir;
	normalize_vec3(&temp_ray.direction);
	update_intersect_all_object(&temp_ray, ptr_scene->objects.data, ptr_scene->objects.size, &inter);
	//if (inter.ptr_obj != NULL && fabs(inter.distance - vec3_norm(light_dir)) > 1e-5)
	if (inter.ptr_obj != NULL && inter.distance < vec3_norm(light_dir))
		return ((t_color) {0});
	coeff = coeff_direct_light(ptr_intersect, light); 
	direct_light = multiply_color_coeff(*object_color(ptr_intersect->ptr_obj), light->object_attr.light.color, coeff);
	coeff = coeff_specular_light(ptr_intersect, *ptr_intersect->ray, light);
	return (color_add(direct_light, dim_color(light->object_attr.light.color, coeff)));
}

t_color	object_sum_lights(t_intersect *ptr_intersect, t_scene *ptr_scene)
{
	t_color		temp;
	t_object	*crnt_light;
	size_t		i;

	i = 0;
	temp.color = 0;
	while (i < ptr_scene->lights_arr.size)
	{
		crnt_light = &((t_object *)ptr_scene->lights_arr.data)[i];
		temp = color_add(temp, object_single_light(ptr_intersect,
					ptr_scene, crnt_light));
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
	update_intersect_all_object(&ray, obj_array, ptr_scene->objects.size, &intersect_data);
	intersect_data.ray = &ray;
	update_intersect_color(&intersect_data, ptr_scene);
	ptr_pixel->color = intersect_data.crnt_color.color;
	return ;
}
