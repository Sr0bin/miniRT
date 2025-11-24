/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:45:42 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/26 15:15:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "object.h"
#include "vector.h"
#include "parsing.h"

int	obj_fill_type_vec(t_vector *to_fill, t_vector *ptr_objects, t_obj_type type)
{
	int	ret;
	size_t	count;
	t_object *crnt_obj;

	count = 0;
	crnt_obj = search_object(ptr_objects, type, count); 
	while (crnt_obj != NULL)
	{
		ret = ft_vector_add_single(to_fill, crnt_obj);
		if (ret != SUCCESS)
			return (FAILURE_MALLOC);
		crnt_obj = search_object(ptr_objects, type, ++count); 
	}
	return (SUCCESS);
}

int	obj_fill_tangible_vec(t_vector *to_fill, t_vector *ptr_objects)
{
	int	ret;
	size_t	count;
	t_object *crnt_obj;

	count = 0;
	crnt_obj = search_object_group(ptr_objects, OBJ_SPHERE, count); 
	while (crnt_obj != NULL)
	{
		ret = ft_vector_add_single(to_fill, crnt_obj);
		if (ret != SUCCESS)
			return (FAILURE_MALLOC);
		crnt_obj = search_object_group(ptr_objects, OBJ_SPHERE, ++count); 
	}
	return (SUCCESS);
}
void	free_scene(t_scene *scene)
{
	free(scene->lights_arr.data);
	free(scene->objects.data);
}

static void	free_vector_scene(t_vector *vector)
{
	free(vector->data);
}
int	scene_init(t_scene *scene, t_vector *ptr_objects)
{
	int	ret;
	scene->ambient_light = *search_object(ptr_objects, OBJ_AMBIENT, 0);
	scene->camera = *search_object(ptr_objects, OBJ_CAMERA, 0);
	ret = ft_vector_init(&scene->lights_arr, 10, sizeof(t_object) , &free_vector_scene); 
	if (ret != SUCCESS)
		return (FAILURE_MALLOC);
	ret = ft_vector_init(&scene->objects, 10, sizeof(t_object) , &free_vector_scene); 
	if (ret != SUCCESS)
	{
		ft_vector_free(&scene->lights_arr);
		return (FAILURE_MALLOC);
	}
	ret = obj_fill_type_vec(&scene->lights_arr, ptr_objects, OBJ_LIGHT);
	if (ret != SUCCESS)
	{
		free_scene(scene);
		return (FAILURE_MALLOC);
	}
	ret = obj_fill_tangible_vec(&scene->objects, ptr_objects);
	if (ret != SUCCESS)
	{
		free_scene(scene);
		return (FAILURE_MALLOC);
	}
	return (SUCCESS);
}
