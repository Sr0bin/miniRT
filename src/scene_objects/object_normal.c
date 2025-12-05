/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:40:51 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/05 15:35:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "vec3.h"

t_vec3	sphere_normal(t_object *obj, t_point3 hit)
{
	t_vec3	normal;

	normal = vect3_from_point3(obj->coordinates, hit);
	normalize_vec3(&normal);
	return (normal);
}

t_vec3	plane_normal(t_object *obj, t_point3 hit)
{
	(void) hit;
	return(obj->object_attr.plane.direction);
}

t_vec3	intersect_normal(t_intersect *intersect_data)
{
	if (intersect_data->ptr_obj == NULL)
		return ((t_vec3) {0});
	return (object_normal(intersect_data->ptr_obj, intersect_data->intersect_point));
}

t_vec3	object_normal(t_object *obj, t_point3 point)
{
	if (obj->type == OBJ_SPHERE)
		return (sphere_normal(obj, point));
	if (obj->type == OBJ_PLANE)
		return (plane_normal(obj, point));
	return ((t_vec3){0});
}
