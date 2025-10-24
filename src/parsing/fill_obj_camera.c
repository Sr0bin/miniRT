/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:41:38 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:42:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

int	fill_obj_camera(t_object *ptr_obj_tmp, char **elements);

int	fill_obj_camera(t_object *ptr_obj_tmp, char **elements)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_CAMERA;
	if (elements[1] == NULL || elements[2] == NULL
		|| elements[3] == NULL || elements[4] != NULL)
		return (FAILURE_PARSE_WRONG_OBJ_NB_OF_INFO);
	ret = fill_coordinates(&ptr_obj_tmp->coordinates, elements[1]);
	if (ret != 0)
		return (ret);
	ret = fill_direction(&ptr_obj_tmp->object_attr.camera.direction,
			elements[2], -1.0, 1.0);
	if (ret != 0)
		return (ret);
	ret = fill_single_double_range(&ptr_obj_tmp->object_attr.camera.fov,
			elements[3], 0, 180);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}
