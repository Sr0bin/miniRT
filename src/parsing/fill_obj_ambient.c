/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:40:28 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:40:56 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

int	fill_obj_ambient(t_object *ptr_obj_tmp, char **elements);

int	fill_obj_ambient(t_object *ptr_obj_tmp, char **elements)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_AMBIENT;
	if (elements[1] == NULL || elements[2] == NULL || elements[3] != NULL)
		return (FAILURE_PARSE_WRONG_OBJ_NB_OF_INFO);
	ret = fill_single_double_range(&ptr_obj_tmp->object_attr.ambient.ratio,
			elements[1], 0.0, 1.0);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_colors(&ptr_obj_tmp->object_attr.ambient.color.rgba,
			elements[2]);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}
