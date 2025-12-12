/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:20:19 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 11:49:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "minirt.h"
#include "ft_vectors.h"

t_object	*n_object(t_vector *ptr_objects, size_t n)
{
	if (n > ptr_objects->size)
		return (NULL);
	return (&((t_object *) ptr_objects->data)[n]);
}

t_object	*iter_object(t_vector *ptr_objects, int (f)(t_object *))
{
	size_t		count;
	t_object	*objects;

	count = 0;
	objects = ptr_objects->data;
	while (f(&objects[count]) && count < ptr_objects->size)
		count++;
	return (n_object(ptr_objects, count));
}

// search for an object of certain type in vector, skips the n first
t_object	*search_object(t_vector *ptr_objects, t_obj_type type, size_t n)
{
	t_object	*object;
	size_t		i;
	size_t		count;

	object = ptr_objects->data;
	i = 0;
	count = 0;
	while (i < ptr_objects->size)
	{
		if (object[i].type == type)
		{
			count++;
			if (count > n)
				return (&object[i]);
		}
		i++;
	}
	return (NULL);
}

t_object	*search_object_group(t_vector *ptr_objects, t_obj_type type,
				size_t n)
{
	t_object	*object;
	size_t		i;
	size_t		count;

	object = ptr_objects->data;
	i = 0;
	count = 0;
	while (i < ptr_objects->size)
	{
		if (object[i].type >= type)
		{
			count++;
			if (count > n)
				return (&object[i]);
		}
		i++;
	}
	return (NULL);
}
