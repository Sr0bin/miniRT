/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:45:36 by jweber            #+#    #+#             */
/*   Updated: 2025/10/27 18:38:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"

int	fill_obj_cylinder(t_object *ptr_obj_tmp, char **elements);

int	fill_obj_cylinder(t_object *ptr_obj_tmp, char **elem)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_CYLINDER;
	if (elem[1] == NULL || elem[2] == NULL || elem[3] == NULL || elem[4] == NULL
		|| elem[5] == NULL || elem[6] != NULL)
		return (FAILURE_PARSE_WRONG_OBJ_NB_OF_INFO);
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elem[1]);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_direction(&ptr_obj_tmp->object_attr.cylinder.ptr_direction,
			elem[2], -1.0, 1.0);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_single_double(&ptr_obj_tmp->object_attr.cylinder.diameter,
			elem[3]);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_single_double(&ptr_obj_tmp->object_attr.cylinder.height,
			elem[4]);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_colors(&ptr_obj_tmp->object_attr.cylinder.color.rgba, elem[5]);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}
