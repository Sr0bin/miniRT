/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:10:20 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/16 15:12:47 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "minirt.h"
#include "color.h"

static void	obj_set_amb(t_object *ptr_obj, t_color color)
{
	if (ptr_obj->type == OBJ_SPHERE)
		ptr_obj->object_attr.sphere.amb_color = color;
	if (ptr_obj->type == OBJ_PLANE)
		ptr_obj->object_attr.plane.amb_color = color;
	if (ptr_obj->type == OBJ_CYLINDER)
		ptr_obj->object_attr.cylinder.amb_color = color;
	if (ptr_obj->type == OBJ_LIGHT)
		ptr_obj->object_attr.light.amb_color = color;
}

void	obj_update_amb(t_object *ptr_obj, void *ptr_scene)
{
	t_color	ambient_color;
	double	coeff;
	t_scene	scene;

	scene = *(t_scene *)ptr_scene;
	ambient_color = scene.ambient_light.object_attr.ambient.color;
	coeff = scene.ambient_light.object_attr.ambient.ratio;
	obj_set_amb(ptr_obj,
		multiply_color_coeff(*object_color(ptr_obj), ambient_color, coeff));
}

t_color	object_ambient_color(t_object *ptr_obj, t_scene scene)
{
	(void) scene;
	if (ptr_obj->type == OBJ_SPHERE)
		return (ptr_obj->object_attr.sphere.amb_color);
	if (ptr_obj->type == OBJ_PLANE)
		return (ptr_obj->object_attr.plane.amb_color);
	if (ptr_obj->type == OBJ_CYLINDER)
		return (ptr_obj->object_attr.cylinder.amb_color);
	if (ptr_obj->type == OBJ_LIGHT)
		return (ptr_obj->object_attr.light.amb_color);
	return ((t_color){0});
}
