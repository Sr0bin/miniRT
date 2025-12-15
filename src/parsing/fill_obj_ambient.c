/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_ambient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:40:28 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 14:06:35 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_string.h"
#include "ft_standard.h"

int			fill_obj_ambient(t_object *ptr_obj_tmp, char **elements,
				char **ptr_str_err_msg);
static int	atof_failed(int ret, char *ratio_str,
				char **ptr_str_err_msg);
static int	wrong_ratio_value(char *ratio_str, char **ptr_str_err_msg);
static int	ambient_color_failed(int ret, char **ptr_str_err_msg);

/* to check
 *	wrong nb elements : DONE -> OK !
 *	ft_strdup fail : DONE -> OK !
 *	ft_atof_safe fail : DONE -> OK !
 *	wrong_object_ratio : DONE -> OK !
 *	fill_colors fail : DONE -> OK !
*/

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
		return (atof_failed(ret, elements[1], ptr_str_err_msg));
	if (ptr_obj_tmp->object_attr.ambient.ratio < 0
		|| ptr_obj_tmp->object_attr.ambient.ratio > 1)
		return (wrong_ratio_value(elements[1], ptr_str_err_msg));
	ret = fill_colors(&ptr_obj_tmp->object_attr.ambient.color.rgba,
			elements[2], ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ambient_color_failed(ret, ptr_str_err_msg));
	return (SUCCESS);
}

static int	atof_failed(int ret, char *ratio_str,
				char **ptr_str_err_msg)
{
	ret = init_msg_atof_failed(ptr_str_err_msg, ret, ratio_str);
	if (ret == FAILURE_MALLOC)
		return (ret);
	*ptr_str_err_msg
		= ft_strjoin_free_second("Ambient ratio:\n", *ptr_str_err_msg);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (ret);
}

static int	wrong_ratio_value(char *ratio_str, char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strdup("Ambient ratio:\n'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			ratio_str);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"': ratio value must be between 0.0 and 1.0\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	ambient_color_failed(int ret, char **ptr_str_err_msg)
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
