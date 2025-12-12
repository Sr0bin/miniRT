/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:24:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 11:01:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "intersection.h"
#include <stdio.h>

static int	update_intersect_object(t_ray ray, t_object	*obj,
				t_intersect *ptr_intersect);
static void	update_closest_intersect(t_intersect *ptr_intersect,
				t_intersect *ptr_intersect_tmp);
static int	update_closest_intersect_return(t_intersect *ptr_intersect,
				t_intersect *ptr_intersect_tmp);

int	update_intersect_all_object(t_ray *ray, t_object *obj_array,
		size_t count, t_intersect *ptr_intersect)
{
	size_t	obj_i;
	int		hit;

	obj_i = 0;
	hit = 0;
	while (obj_i < count)
	{
		hit |= update_intersect_object(*ray, &obj_array[obj_i], ptr_intersect);
		obj_i++;
	}
	return (hit);
}

static int	update_intersect_object(t_ray ray, t_object	*obj,
				t_intersect *ptr_intersect)
{
	t_intersect	intersect_data_tmp;

	intersect_data_tmp.ptr_obj = obj;
	if (obj->type == OBJ_SPHERE)
	{
		if (check_intersect_sphere(ray, *obj, &intersect_data_tmp) == TRUE)
			return (update_closest_intersect_return(ptr_intersect,
					&intersect_data_tmp));
	}
	else if (obj->type == OBJ_PLANE)
	{
		if (check_intersect_plane(ray, *obj, &intersect_data_tmp) == TRUE)
			return (update_closest_intersect_return(ptr_intersect,
					&intersect_data_tmp));
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		if (check_intersect_cylinder(ray, *obj, &intersect_data_tmp) == TRUE)
			return (update_closest_intersect_return(ptr_intersect,
					&intersect_data_tmp));
	}
	return (FALSE);
}

int	update_closest_intersect_return(t_intersect *ptr_intersect,
				t_intersect *ptr_intersect_tmp)
{
	update_closest_intersect(ptr_intersect, ptr_intersect_tmp);
	return (TRUE);
}

static void	update_closest_intersect(t_intersect *ptr_intersect,
				t_intersect *ptr_intersect_tmp)
{
	if (ptr_intersect->ptr_obj == NULL)
		*ptr_intersect = *ptr_intersect_tmp;
	else if (ptr_intersect_tmp->distance < ptr_intersect->distance)
		*ptr_intersect = *ptr_intersect_tmp;
}

/*
void	offset_intersect_point(t_intersect *intersect_data)
{
	intersect_data->intersect_point = offset_point3(
			intersect_data->intersect_point,
			vec3_scale(intersect_normal(intersect_data), 0.001));
}
*/
