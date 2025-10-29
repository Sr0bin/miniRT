/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:45:36 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 15:05:55 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"
#include "ft_standard.h"
#include "ft_string.h"

int	fill_obj_cylinder(t_object *ptr_obj_tmp, char **elem,
		char **ptr_str_err_msg);

int	fill_obj_cylinder(t_object *ptr_obj_tmp, char **elem,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_CYLINDER;
	if (elem[1] == NULL || elem[2] == NULL || elem[3] == NULL || elem[4] == NULL
		|| elem[5] == NULL || elem[6] != NULL)
	{
		*ptr_str_err_msg = ft_strdup(MSG_CYLINDER_WRONG_ARGUMENTS);
		if (ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_CAMERA_WRONG_OBJ_NB_OF_INFO);
	}
	ret = ft_atof_safe(elem[3], &ptr_obj_tmp->object_attr.cylinder.diameter);
	if (ret != SUCCESS)
	{
		*ptr_str_err_msg = ft_strdup("could not convert value : [VALUE_STR]\n");
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = ft_atof_safe(elem[4], &ptr_obj_tmp->object_attr.cylinder.height);
	if (ret != SUCCESS)
	{
		*ptr_str_err_msg = ft_strdup("could not convert value : [VALUE_STR]\n");
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = fill_colors(&ptr_obj_tmp->object_attr.cylinder.color.rgba, elem[5],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elem[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_direction(&ptr_obj_tmp->object_attr.cylinder.ptr_direction,
			elem[2], ptr_str_err_msg);
	if (ret != SUCCESS)
	{
		// TO DO FREE ici coordinates d'avant 
		return (ret);
	}
	return (SUCCESS);
}
