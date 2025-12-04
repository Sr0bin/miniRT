/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:24:27 by jweber            #+#    #+#             */
/*   Updated: 2025/12/04 14:07:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "point3.h"
#include "ray.h"
#include "vec3.h"
#include "render.h"
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

void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_scene *ptr_scene)
{
	size_t		obj_i;
	t_object	*obj_array;
	t_intersect	intersect_data;
	t_intersect	intersect_data_tmp;
	int			ret;

	obj_array = ptr_scene->objects.data;
	intersect_data.ptr_obj = NULL;
	obj_i = 0;
	while (obj_i < ptr_scene->objects.size)
	{
		intersect_data_tmp.ptr_obj = obj_array + obj_i;
		if (obj_array[obj_i].type == OBJ_SPHERE)
		{
			ret = check_intersect_sphere(ray, obj_array[obj_i], &intersect_data_tmp);
			if (ret == TRUE)
			{
				if (intersect_data.ptr_obj == NULL)
					intersect_data = intersect_data_tmp;
				else
					if (intersect_data_tmp.distance < intersect_data.distance)
						intersect_data = intersect_data_tmp;
			}
		}
		else if (obj_array[obj_i].type == OBJ_PLANE)
		{
			ret = check_intersect_plane(ray, obj_array[obj_i], &intersect_data_tmp);
			if (ret == TRUE)
			{
				if (intersect_data.ptr_obj == NULL)
					intersect_data = intersect_data_tmp;
				else
					if (intersect_data_tmp.distance < intersect_data.distance)
						intersect_data = intersect_data_tmp;
			}
		}
		obj_i++;
	}
	if (intersect_data.ptr_obj != NULL)
	{
		if (intersect_data.ptr_obj->type == OBJ_SPHERE)
			ptr_pixel->color = intersect_data.ptr_obj->object_attr.sphere.color.color;
		if (intersect_data.ptr_obj->type == OBJ_PLANE)
			ptr_pixel->color = intersect_data.ptr_obj->object_attr.plane.color.color;
	}
	return ;
}
