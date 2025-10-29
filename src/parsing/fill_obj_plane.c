/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:45:04 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 15:06:03 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_string.h"

int	fill_obj_plane(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg);

int	fill_obj_plane(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_PLANE;
	if (elements[1] == NULL || elements [2] == NULL
		|| elements [3] == NULL || elements [4] != NULL)
	{
		*ptr_str_err_msg = ft_strdup(MSG_PLANE_WRONG_ARGUMENTS);
		if (ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_CAMERA_WRONG_OBJ_NB_OF_INFO);
	}
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_direction(&ptr_obj_tmp->object_attr.plane.ptr_direction,
			elements[2], ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_colors(&ptr_obj_tmp->object_attr.plane.color.rgba,
			elements[3], ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}
