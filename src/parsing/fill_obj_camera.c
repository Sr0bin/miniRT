/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:41:38 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 15:05:49 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_standard.h"
#include "ft_string.h"

int	fill_obj_camera(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg);

int	fill_obj_camera(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_CAMERA;
	if (elements[1] == NULL || elements[2] == NULL
		|| elements[3] == NULL || elements[4] != NULL)
	{
		*ptr_str_err_msg = ft_strdup(MSG_CAMERA_WRONG_ARGUMENTS);
		if (ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_CAMERA_WRONG_OBJ_NB_OF_INFO);
	}
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != 0)
		return (ret);
	ret = fill_direction(&ptr_obj_tmp->object_attr.camera.ptr_direction,
			elements[2], ptr_str_err_msg);
	if (ret != 0)
		return (ret);
	/*
	ret = fill_single_double_range(&ptr_obj_tmp->object_attr.camera.fov,
			elements[3], ptr_str_err_msg);
	if (ret != 0)
		return (ret);
	*/
	ret = ft_atof_safe(elements[3], &ptr_obj_tmp->object_attr.camera.fov);
	if (ret != SUCCESS)
	{
		*ptr_str_err_msg = ft_strdup("could not convert value : [VALUE_STR]\n");
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	if (ptr_obj_tmp->object_attr.camera.fov <= 0
		|| ptr_obj_tmp->object_attr.camera.fov >= 180)
	{
		*ptr_str_err_msg = ft_strdup("wrong fov value : 0 < fov < 180\n");
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	return (ret);
}
