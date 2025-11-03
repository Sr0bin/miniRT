/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:44:29 by jweber            #+#    #+#             */
/*   Updated: 2025/11/03 11:34:38 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "minirt.h"
#include "parsing.h"

int			fill_obj_sphere(t_object *ptr_obj_tmp, char **elements,
				char **ptr_str_err_msg);
static int	fill_sphere_diameter(char *diamater_str, double *ptr_diamter,
				char **ptr_str_err_msg);

int	fill_obj_sphere(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_SPHERE;
	if (elements[1] == NULL || elements [2] == NULL
		|| elements[3] == NULL || elements[4] != NULL)
	{
		*ptr_str_err_msg = ft_strdup(MSG_SPHERE_WRONG_ARGUMENTS);
		if (ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = fill_sphere_diameter(elements[2],
			&ptr_obj_tmp->object_attr.sphere.diameter, ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Sphere diameter:\n", ret, ptr_str_err_msg));
	ret = fill_colors(&ptr_obj_tmp->object_attr.sphere.color.rgba,
			elements[3], ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Sphere colors:\n", ret, ptr_str_err_msg));
	ret = fill_coordinates(&ptr_obj_tmp->ptr_coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Sphere coordinates:\n", ret, ptr_str_err_msg));
	return (SUCCESS);
}

static int	fill_sphere_diameter(char *diameter_str, double *ptr_diameter,
				char **ptr_str_err_msg)
{
	int	ret;

	ret = ft_atof_safe(diameter_str, ptr_diameter);
	if (ret != SUCCESS)
		return (init_msg_atof_failed(ptr_str_err_msg, ret, diameter_str));
	return (SUCCESS);
}
