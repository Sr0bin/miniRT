/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:40:51 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/08 14:22:17 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "minirt.h"
#include "vec3.h"
#include "vec4.h"

t_vec3	sphere_normal(t_object *obj, t_point3 hit)
{
	t_vec3	normal;

	normal = vect3_from_point3(obj->coordinates, hit);
	normalize_vec3(&normal);
	return (normal);
}

t_vec3	plane_normal(t_object *obj, t_intersect  *intersect_data)
{
	t_vec3	normal;
	// t_vec4	plane_vec;
	// t_vec4	point_vec;
	t_plane	*plane;

	plane = &obj->object_attr.plane;
	normal = obj->object_attr.plane.direction;
	if (dot_product3(intersect_data->ray->direction, plane->direction) > 0)
		return(normal);
	return(vec3_scale(normal, -1));
}

t_vec3	intersect_normal(t_intersect *intersect_data)
{
	if (intersect_data->ptr_obj == NULL)
		return ((t_vec3) {0});
	return (object_normal(intersect_data->ptr_obj, intersect_data));
}

t_vec3	object_normal(t_object *obj, t_intersect *intersect_data)
{
	if (obj->type == OBJ_SPHERE)
		return (sphere_normal(obj, intersect_data->intersect_point));
	if (obj->type == OBJ_PLANE)
		return (plane_normal(obj, intersect_data));
	if (obj->type == OBJ_CYLINDER)
	{
		return (intersect_data->normal);
	}
	return ((t_vec3){0});
}
