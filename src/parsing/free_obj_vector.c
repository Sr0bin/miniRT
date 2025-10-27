/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:38:06 by jweber            #+#    #+#             */
/*   Updated: 2025/10/27 18:58:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "point.h"
#include "vector.h"

void	free_obj_vector(t_vector *ptr_vec);

void	free_obj_vector(t_vector *ptr_vec)
{
	t_object	*ptr_obj;
	size_t		i;

	i = 0;
	while (i < ptr_vec->size)
	{
		ptr_obj = &((t_object *)ptr_vec->data)[i];
		if (ptr_obj->type != OBJ_AMBIENT)
			free_point(ptr_obj->ptr_coordinates);
		if (ptr_obj->type == OBJ_PLANE)
			free_vector(ptr_obj->object_attr.plane.ptr_direction);
		if (ptr_obj->type == OBJ_CAMERA)
			free_vector(ptr_obj->object_attr.camera.ptr_direction);
		if (ptr_obj->type == OBJ_CYLINDER)
			free_vector(ptr_obj->object_attr.cylinder.ptr_direction);
		if (ptr_obj->type == OBJ_LIGHT)
			free_vector(ptr_obj->object_attr.light.ptr_direction);
		i++;
	}
	free(ptr_vec->data);
	ptr_vec->data = NULL;
	ptr_vec->data_size = 0;
	ptr_vec->size = 0;
	ptr_vec->capacity = 0;
}
