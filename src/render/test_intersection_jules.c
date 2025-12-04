/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:24:27 by jweber            #+#    #+#             */
/*   Updated: 2025/12/04 18:55:48 by rorollin         ###   ########.fr       */
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

void		update_intersect_object(t_ray ray, t_object	*obj, t_intersect *intersect_data)
{
	t_intersect	intersect_data_tmp;
	int		ret;

	intersect_data_tmp.ptr_obj = obj;
	if (obj->type == OBJ_SPHERE)
	{
		ret = check_intersect_sphere(ray, *obj, &intersect_data_tmp);
		if (ret == TRUE)
			update_closest_intersect(intersect_data, &intersect_data_tmp);
	}
	else if (obj->type == OBJ_PLANE)
	{
		ret = check_intersect_plane(ray, *obj, &intersect_data_tmp);
		if (ret == TRUE)
			update_closest_intersect(intersect_data, &intersect_data_tmp);
	}
}
// t_color	object_ambient_color(t_object object, t_scene scene)
// {
// 	t_color	temp;
// 	t_rgba	temp_rgba;
// 	t_rgba	object_rgba;
// 	t_rgba	ambient_rgba;
//
// 	object_rgba = object.color.rgba;
// 	temp_rgba
// }

void	update_intersect_color(t_intersect	*intersect_data, t_scene *ptr_scene)
{
	(void) *ptr_scene;
	//belek : si il n'y a pas de hit, mettre la backround color
	if (intersect_data->ptr_obj != NULL)
	{
		if (intersect_data->ptr_obj->type == OBJ_SPHERE)
			intersect_data->crnt_color = intersect_data->ptr_obj->object_attr.sphere.color;
		if (intersect_data->ptr_obj->type == OBJ_PLANE)
			intersect_data->crnt_color = intersect_data->ptr_obj->object_attr.plane.color;
	}

}
void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_scene *ptr_scene)
{
	size_t		obj_i;
	t_object	*obj_array;
	t_intersect	intersect_data;

	obj_array = ptr_scene->objects.data;
	intersect_data.ptr_obj = NULL;
	obj_i = 0;
	while (obj_i < ptr_scene->objects.size)
	{

		update_intersect_object(ray, &obj_array[obj_i], &intersect_data);
		obj_i++;
	}
	update_intersect_color(&intersect_data, ptr_scene);
	ptr_pixel->color = intersect_data.crnt_color.color;
	return ;
}
