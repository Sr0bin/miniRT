/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:42:25 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 15:05:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_standard.h"
#include "ft_string.h"

int	fill_obj_light(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg);

int	fill_obj_light(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_LIGHT;
	if (elements[1] == NULL || elements[2] == NULL
		|| elements[3] == NULL || elements[4] != NULL)
	{
		*ptr_str_err_msg = ft_strdup(MSG_LIGHT_WRONG_ARGUMENTS);
		if (ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_CAMERA_WRONG_OBJ_NB_OF_INFO);
	}
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	ret = ft_atof_safe(elements[2], &ptr_obj_tmp->object_attr.light.brightness);
	if (ret != SUCCESS)
	{
		*ptr_str_err_msg = ft_strdup("could not convert value : [VALUE_STR]\n");
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	if (ptr_obj_tmp->object_attr.light.brightness <= 0.0
		|| ptr_obj_tmp->object_attr.light.brightness >= 1.0)
	{
		*ptr_str_err_msg = ft_strdup("wrong ratio value : 0"
			" <= brightness <= 1\n");
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = fill_colors(&ptr_obj_tmp->object_attr.light.color.rgba, elements[3],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}
