/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:09:12 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 13:50:18 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "ft_string.h"
#include "ft_memory.h"
#include "minirt.h"

int	fill_obj_content(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg);

int	fill_obj_content(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	if (elements[0] == NULL)
	{
		*ptr_str_err_msg = ft_strdup("empty line\n");
		if (ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ft_bzero(ptr_obj_tmp, sizeof(*ptr_obj_tmp));
	if (ft_strcmp(elements[0], "A") == 0)
		ret = fill_obj_ambient(ptr_obj_tmp, elements, ptr_str_err_msg);
	else if (ft_strcmp(elements[0], "C") == 0)
		ret = fill_obj_camera(ptr_obj_tmp, elements, ptr_str_err_msg);
	else if (ft_strcmp(elements[0], "L") == 0)
		ret = fill_obj_light(ptr_obj_tmp, elements, ptr_str_err_msg);
	else if (ft_strcmp(elements[0], "sp") == 0)
		ret = fill_obj_sphere(ptr_obj_tmp, elements, ptr_str_err_msg);
	else if (ft_strcmp(elements[0], "pl") == 0)
		ret = fill_obj_plane(ptr_obj_tmp, elements, ptr_str_err_msg);
	else if (ft_strcmp(elements[0], "cy") == 0)
		ret = fill_obj_cylinder(ptr_obj_tmp, elements, ptr_str_err_msg);
	else
	{
		*ptr_str_err_msg = ft_strdup("unexepected identifier : [IDENTIFIER]\n");
		if (ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	return (ret);
}
