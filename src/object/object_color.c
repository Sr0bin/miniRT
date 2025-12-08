/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:15:20 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/08 17:21:30 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "object.h"
#include "color.h"

t_color	*object_color(t_object	*ptr_obj)
{
	if (ptr_obj->type == OBJ_SPHERE)
		return (&ptr_obj->object_attr.sphere.color);
	if (ptr_obj->type == OBJ_PLANE)
		return (&ptr_obj->object_attr.plane.color);
	if (ptr_obj->type == OBJ_CYLINDER)
		return (&ptr_obj->object_attr.cylinder.color);
	if (ptr_obj->type == OBJ_LIGHT)
		return (&ptr_obj->object_attr.light.color);
	return (NULL);
}

t_color	object_ambient_color(t_object *ptr_obj, t_scene scene)
{
	t_color	ambient_color;
	double	coeff;

	ambient_color = scene.ambient_light.object_attr.ambient.color;
	coeff = scene.ambient_light.object_attr.ambient.ratio;
	return (multiply_color_coeff(*object_color(ptr_obj), ambient_color, coeff));
}
