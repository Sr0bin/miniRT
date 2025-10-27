/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:45:04 by jweber            #+#    #+#             */
/*   Updated: 2025/10/27 18:38:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

int	fill_obj_plane(t_object *ptr_obj_tmp, char **elements);

int	fill_obj_plane(t_object *ptr_obj_tmp, char **elements)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_PLANE;
	if (elements[1] == NULL || elements [2] == NULL
		|| elements [3] == NULL || elements [4] != NULL)
		return (FAILURE_PARSE_WRONG_OBJ_NB_OF_INFO);
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elements[1]);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_direction(&ptr_obj_tmp->object_attr.plane.ptr_direction,
			elements[2], -1.0, 1.0);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_colors(&ptr_obj_tmp->object_attr.plane.color.rgba,
			elements[3]);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}
