/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:42:25 by jweber            #+#    #+#             */
/*   Updated: 2025/11/03 11:33:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_standard.h"
#include "ft_string.h"

int			fill_obj_light(t_object *ptr_obj_tmp, char **elements,
				char **ptr_str_err_msg);
static int	fill_light_brightness(char *brightness_str, double *ptr_brightness,
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
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = fill_light_brightness(elements[2],
			&ptr_obj_tmp->object_attr.light.brightness, ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Light brightness:\n", ret, ptr_str_err_msg));
	ret = fill_colors(&ptr_obj_tmp->object_attr.light.color.rgba, elements[3],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Light colors:\n", ret, ptr_str_err_msg));
	ret = fill_coordinates(&ptr_obj_tmp->coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Light coordinates:\n", ret, ptr_str_err_msg));
	return (SUCCESS);
}

static int	fill_light_brightness(char *brightness_str, double *ptr_brightness,
				char **ptr_str_err_msg)
{
	int	ret;

	ret = ft_atof_safe(brightness_str, ptr_brightness);
	if (ret != SUCCESS)
		return (init_msg_atof_failed(ptr_str_err_msg, ret, brightness_str));
	if (*ptr_brightness <= 0.0 || *ptr_brightness >= 1.0)
	{
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
				brightness_str);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
				"': wrong brightness value: 0.0 < brightness < 1.0\n");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	return (SUCCESS);
}
