/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:53:13 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 14:50:18 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "point.h"
#include "ray.h"
#include "vector.h"
#include "render.h"
#include <math.h>

int		check_intersect_sphere(t_ray ray, t_object sphere,
			double intersect_point[3]);
void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_vector objects);

int	test_intersection_jules(t_ray *ray_array, size_t nb_rays,
		t_color *pixel_array, t_vector objects)
{
	size_t	x_i;

	x_i = 0;
	while (x_i < nb_rays)
	{
		//printf("ray %zu, ", x_i);
		set_pixel_color(ray_array[x_i], pixel_array + x_i, objects);
		x_i++;
	}
	return (0);
}

typedef struct s_intersect
{
	double		intersect_point[3];
	t_object	*ptr_obj;
	double		distance;
} t_intersect;

void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_vector objects)
{
	size_t		obj_i;
	t_object	*obj_array;
	t_intersect	intersect_data;
	double		distance_tmp;
	double		intersect_point_tmp[3];
	int			ret;

	obj_array = objects.data;
	intersect_data.ptr_obj = NULL;
	intersect_data.intersect_point[0] = 0;
	intersect_data.intersect_point[1] = 0;
	intersect_data.intersect_point[2] = 0;
	intersect_data.distance = 0;
	obj_i = 3;
	while (obj_i < objects.size)
	{
		intersect_point_tmp[0] = 0;
		intersect_point_tmp[1] = 0;
		intersect_point_tmp[2] = 0;
		if (obj_array[obj_i].type == OBJ_SPHERE)
		{
			ret = check_intersect_sphere(ray, obj_array[obj_i], intersect_point_tmp);
			if (ret == TRUE)
			{
				if (intersect_data.ptr_obj == NULL)
				{
					intersect_data.intersect_point[0] = intersect_point_tmp[0];
					intersect_data.intersect_point[1] = intersect_point_tmp[1];
					intersect_data.intersect_point[2] = intersect_point_tmp[2];
					intersect_data.distance = my_norm_from_vec(intersect_data.intersect_point);
					intersect_data.ptr_obj = obj_array + obj_i;
				}
				else
				{
					distance_tmp = my_norm_from_vec(intersect_point_tmp);
					if (distance_tmp < intersect_data.distance)
					{
						intersect_data.intersect_point[0] = intersect_point_tmp[0];
						intersect_data.intersect_point[1] = intersect_point_tmp[1];
						intersect_data.intersect_point[2] = intersect_point_tmp[2];
						intersect_data.distance = distance_tmp;
						intersect_data.ptr_obj = obj_array + obj_i;
					}
				}
			}
		}
		else if (obj_array[obj_i].type == OBJ_PLANE)
		{
			ret = check_intersect_plane(ray, obj_array[obj_i], intersect_point_tmp);
			if (ret == TRUE)
			{
				if (intersect_data.ptr_obj == NULL)
				{
					intersect_data.intersect_point[0] = intersect_point_tmp[0];
					intersect_data.intersect_point[1] = intersect_point_tmp[1];
					intersect_data.intersect_point[2] = intersect_point_tmp[2];
					intersect_data.distance = my_norm_from_vec(intersect_data.intersect_point);
					intersect_data.ptr_obj = obj_array + obj_i;
				}
				else
				{
					distance_tmp = my_norm_from_vec(intersect_point_tmp);
					if (distance_tmp < intersect_data.distance)
					{
						intersect_data.intersect_point[0] = intersect_point_tmp[0];
						intersect_data.intersect_point[1] = intersect_point_tmp[1];
						intersect_data.intersect_point[2] = intersect_point_tmp[2];
						intersect_data.distance = distance_tmp;
						intersect_data.ptr_obj = obj_array + obj_i;
					}
				}
			}
		}
		obj_i++;
	}
	if (intersect_data.ptr_obj != NULL)
		ptr_pixel->color = intersect_data.ptr_obj->object_attr.sphere.color.color;
	return ;
}
