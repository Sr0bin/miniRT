/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:41:38 by jweber            #+#    #+#             */
/*   Updated: 2025/10/31 12:57:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "minirt.h"
#include "parsing.h"
#include "ft_standard.h"
#include "ft_string.h"

static int	fill_camera_fov(char *elem, double *ptr_camera_fov,
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
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = fill_camera_fov(elements[3], &ptr_obj_tmp->object_attr.camera.fov,
			ptr_str_err_msg);
	if (ret != 0)
	{
		if (ret == FAILURE_PARSE_PERSONNALIZED)
		{
			*ptr_str_err_msg = ft_strjoin_free_second("Camera FOV:\n",
					*ptr_str_err_msg);
			if (*ptr_str_err_msg == NULL)
				return (FAILURE_MALLOC);
		}
		return (ret);
	}
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
	{
		if (ret == FAILURE_PARSE_PERSONNALIZED)
		{
			*ptr_str_err_msg = ft_strjoin_free_second("Camera coordinates:\n",
					*ptr_str_err_msg);
			if (*ptr_str_err_msg == NULL)
				return (FAILURE_MALLOC);
		}
		return (ret);
	}
	ret = fill_direction(&ptr_obj_tmp->object_attr.camera.ptr_direction,
			elements[2], ptr_str_err_msg);
	if (ret != 0)
	{
		free_matrix(ptr_obj_tmp->ptr_coordinates);
		if (ret == FAILURE_PARSE_PERSONNALIZED)
		{
			*ptr_str_err_msg = ft_strjoin_free_second("Camera direction:\n",
					*ptr_str_err_msg);
			if (*ptr_str_err_msg == NULL)
				return (FAILURE_MALLOC);
		}
		return (ret);
	}
	return (ret);
}


static int	fill_camera_fov(char *elem, double *ptr_camera_fov, char **ptr_str_err_msg)
{
	int	ret;

	ret = ft_atof_safe(elem, ptr_camera_fov);
	if (ret != SUCCESS)
	{
		return (init_msg_atof_failed(ptr_str_err_msg, ret, elem));
	}
	if (*ptr_camera_fov <= 0 || *ptr_camera_fov >= 180)
	{
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, elem);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
				"': wrong FOV value: 0 < FOV < 180\n");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	return (SUCCESS);
}
