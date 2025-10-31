/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:40:28 by jweber            #+#    #+#             */
/*   Updated: 2025/10/31 12:54:24 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_string.h"
#include "ft_standard.h"

int	fill_obj_ambient(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg);

int	fill_obj_ambient(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_AMBIENT;
	if (elements[1] == NULL || elements[2] == NULL || elements[3] != NULL)
	{
		*ptr_str_err_msg = ft_strdup(MSG_AMBIENT_WRONG_ARGUMENTS);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = ft_atof_safe(elements[1], &ptr_obj_tmp->object_attr.ambient.ratio);
	if (ret != SUCCESS)
	{
		ret = init_msg_atof_failed(ptr_str_err_msg, ret, elements[1]);
		if (ret == FAILURE_MALLOC)
			return (ret);
		*ptr_str_err_msg = ft_strjoin_free_second("Ambient ratio:\n", *ptr_str_err_msg);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (ret);
	}
	if (ptr_obj_tmp->object_attr.ambient.ratio <= 0
		|| ptr_obj_tmp->object_attr.ambient.ratio >= 1)
	{
		*ptr_str_err_msg = ft_strdup("Ambient ratio:\n'");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
				elements[1]);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
				"': ratio value must be between 0.0 and 1.0\n");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = fill_colors(&ptr_obj_tmp->object_attr.ambient.color.rgba,
			elements[2], ptr_str_err_msg);
	if (ret != SUCCESS)
	{
		if (ret == FAILURE_PARSE_PERSONNALIZED)
		{
			*ptr_str_err_msg = ft_strjoin_free_second("Ambient colors:\n",
					*ptr_str_err_msg);
			if (*ptr_str_err_msg == NULL)
				return (FAILURE_MALLOC);
		}
		return (ret);
	}
	return (SUCCESS);
}
