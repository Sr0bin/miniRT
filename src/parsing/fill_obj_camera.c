/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:41:38 by jweber            #+#    #+#             */
/*   Updated: 2025/11/27 18:57:14 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "minirt.h"
#include "parsing.h"
#include "ft_standard.h"
#include "ft_string.h"

static int	fill_camera_fov(char *elem, double *ptr_camera_fov,
				char **ptr_str_err_msg);
static int	camera_wrong_nb_args(char **ptr_str_err_msg);

int	fill_obj_camera(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_CAMERA;
	if (elements[1] == NULL || elements[2] == NULL
		|| elements[3] == NULL || elements[4] != NULL)
		return (camera_wrong_nb_args(ptr_str_err_msg));
	ret = fill_camera_fov(elements[3], &ptr_obj_tmp->object_attr.camera.fov,
			ptr_str_err_msg);
	if (ret != 0)
		return (fail_add_msg("Camera FOV:\n", ret, ptr_str_err_msg));
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Camera coordinates:\n", ret, ptr_str_err_msg));
	ret = fill_direction(&ptr_obj_tmp->object_attr.camera.ptr_direction,
			elements[2], ptr_str_err_msg);
	if (ret != 0)
	{
		free_point(ptr_obj_tmp->ptr_coordinates);
		return (fail_add_msg("Camera direction:\n", ret, ptr_str_err_msg));
	}
	return (ret);
}

static int	camera_wrong_nb_args(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strdup(MSG_CAMERA_WRONG_ARGUMENTS);
	if (ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	fill_camera_fov(char *elem, double *ptr_camera_fov,
				char **ptr_str_err_msg)
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
