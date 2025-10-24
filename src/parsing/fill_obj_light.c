/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:42:25 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:44:15 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

int	fill_obj_light(t_object *ptr_obj_tmp, char **elements);

int	fill_obj_light(t_object *ptr_obj_tmp, char **elements)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_LIGHT;
	if (elements[1] == NULL || elements[2] == NULL
		|| elements[3] == NULL || elements[4] != NULL)
		return (FAILURE_PARSE_WRONG_OBJ_NB_OF_INFO);
	ret = fill_coordinates(&ptr_obj_tmp->coordinates, elements[1]);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_single_double_range(&ptr_obj_tmp->object_attr.light.brightness,
			elements[2], 0.0, 1.0);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_colors(&ptr_obj_tmp->object_attr.light.color.rgba, elements[3]);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}
