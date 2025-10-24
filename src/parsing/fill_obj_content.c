/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:09:12 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:56:12 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "ft_string.h"
#include "ft_memory.h"
#include "minirt.h"

int	fill_obj_content(t_object *ptr_obj_tmp, char **elements);

int	fill_obj_content(t_object *ptr_obj_tmp, char **elements)
{
	if (elements[0] == NULL)
		return (FAILURE_PARSE_EMPTY_LINE);
	ft_bzero(ptr_obj_tmp, sizeof(*ptr_obj_tmp));
	if (ft_strcmp(elements[0], "A") == 0)
		return (fill_obj_ambient(ptr_obj_tmp, elements));
	else if (ft_strcmp(elements[0], "C") == 0)
		return (fill_obj_camera(ptr_obj_tmp, elements));
	else if (ft_strcmp(elements[0], "L") == 0)
		return (fill_obj_light(ptr_obj_tmp, elements));
	else if (ft_strcmp(elements[0], "sp") == 0)
		return (fill_obj_sphere(ptr_obj_tmp, elements));
	else if (ft_strcmp(elements[0], "pl") == 0)
		return (fill_obj_plane(ptr_obj_tmp, elements));
	else if (ft_strcmp(elements[0], "cy") == 0)
		return (fill_obj_cylinder(ptr_obj_tmp, elements));
	else
		return (FAILURE_PARSE_WRONG_OBJ_IDENTIFIER);
}
