/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:32:48 by jweber            #+#    #+#             */
/*   Updated: 2025/11/26 14:58:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "printing.h"
#include "parsing.h"

static void	sort_objects(t_vector *ptr_objects);
static int	check_correct_mandatory_obj(t_vector *ptr_objects);

int	check_objects(t_vector *ptr_objects)
{
	int			ret;

	sort_objects(ptr_objects);
	ret = check_correct_mandatory_obj(ptr_objects);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}

static int	check_correct_mandatory_obj(t_vector *ptr_objects)
{
	size_t	i;
	int		nb_ambient;
	int		nb_camera;
	int		nb_light;

	i = 0;
	nb_ambient = 0;
	nb_camera = 0;
	nb_light = 0;
	while (i < ptr_objects->size)
	{
		if (((t_object *)ptr_objects->data)[i].type == OBJ_AMBIENT)
			nb_ambient++;
		if (((t_object *)ptr_objects->data)[i].type == OBJ_LIGHT)
			nb_light++;
		if (((t_object *)ptr_objects->data)[i].type == OBJ_CAMERA)
			nb_camera++;
		i++;
	}
	if (nb_ambient != 1)
		return (FAILURE_PARSE_WRONG_NB_AMBIENT);
	if (nb_light != 1)
		return (FAILURE_PARSE_WRONG_NB_LIGHT);
	if (nb_camera != 1)
		return (FAILURE_PARSE_WRONG_NB_CAMERA);
	return (SUCCESS);
}

static void	sort_objects(t_vector *ptr_objects)
{
	size_t		i;
	size_t		j;
	t_object	object_tmp;
	t_object	*object_array;

	if (ptr_objects->size <= 1)
		return ;
	i = 0;
	object_array = (t_object *) ptr_objects->data;
	while (i < ptr_objects->size - 1)
	{
		j = 0;
		while (j < ptr_objects->size - 1)
		{
			if (object_array[j + 1].type < object_array[j].type)
			{
				object_tmp = object_array[j];
				object_array[j] = object_array[j + 1];
				object_array[j + 1] = object_tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}
