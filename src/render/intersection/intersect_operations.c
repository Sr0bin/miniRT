/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:24:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/16 16:04:40 by rorollin         ###   ########.fr       */
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

int	update_intersect_light(t_ray *p_ray, t_vector *obj_vector,
				t_intersect *ptr_inter, double distance)
{
	size_t		obj_i;
	size_t		count;
	t_object	*obj_array;

	obj_i = 0;
	count = obj_vector->size;
	obj_array = obj_vector->data;
	while (obj_i < count)
	{
		if (update_intersect_object(*p_ray, &obj_array[obj_i], ptr_inter) != 0)
			if (ptr_inter->distance < distance)
				return (FALSE);
		obj_i++;
	}
	return (TRUE);
}

int	update_intersect_all_object(t_ray *ptr_ray, t_object *obj_array,
		size_t count, t_intersect *ptr_inter)
{
	size_t	obj_i;
	int		hit;

	obj_i = 0;
	hit = 0;
	while (obj_i < count)
	{
		hit |= update_intersect_object(*ptr_ray, &obj_array[obj_i], ptr_inter);
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
