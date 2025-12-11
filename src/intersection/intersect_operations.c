/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:24:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/11 19:00:23 by rorollin         ###   ########.fr       */
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

void	update_closest_intersect(t_intersect *ptr_intersect, t_intersect *ptr_intersect_tmp)
{
	if (ptr_intersect->ptr_obj == NULL)
		*ptr_intersect = *ptr_intersect_tmp;
	else if (ptr_intersect_tmp->distance < ptr_intersect->distance)
		*ptr_intersect = *ptr_intersect_tmp;
}

int	update_intersect_object(t_ray ray, t_object	*obj, t_intersect *ptr_intersect)
{
	t_intersect	intersect_data_tmp;
	int			ret;

	intersect_data_tmp.ptr_obj = obj;
	if (obj->type == OBJ_SPHERE)
	{
		ret = check_intersect_sphere(ray, *obj, &intersect_data_tmp);
		if (ret == TRUE)
		{
			update_closest_intersect(ptr_intersect, &intersect_data_tmp);
			return (TRUE);
		}
	}
	else if (obj->type == OBJ_PLANE)
	{
		ret = check_intersect_plane(ray, *obj, &intersect_data_tmp);
		if (ret == TRUE)
		{
			update_closest_intersect(ptr_intersect, &intersect_data_tmp);
			return (TRUE);
		}
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		ret = check_intersect_cylinder(ray, *obj, &intersect_data_tmp);
		if (ret == TRUE)
		{
			update_closest_intersect(ptr_intersect, &intersect_data_tmp);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	offset_intersect_point(t_intersect *intersect_data)
{

	intersect_data->intersect_point = offset_point3(intersect_data->intersect_point,
		vec3_scale(intersect_normal(intersect_data), 0.001));

}

void	update_intersect_color(t_intersect	*ptr_intersect, t_scene *ptr_scene)
{
	//belek : si il n'y a pas de hit, mettre la backround color
	if (ptr_intersect->ptr_obj != NULL)
	{
		ptr_intersect->crnt_color = object_ambient_color(ptr_intersect->ptr_obj, *ptr_scene);
		ptr_intersect->crnt_color = color_add(ptr_intersect->crnt_color, 
				object_sum_lights(ptr_intersect, ptr_scene));
	}
}

int	update_intersect_all_object(t_ray *ray, t_object *obj_array, 
	size_t count, t_intersect *ptr_intersect)
{
	size_t		obj_i;
	int	hit;

	// intersect_data.ptr_obj = NULL;
	obj_i = 0;
	hit = 0;
	while (obj_i < count)
	{
		hit |= update_intersect_object(*ray, &obj_array[obj_i], ptr_intersect);
		obj_i++;
	}
	return (hit);
}
