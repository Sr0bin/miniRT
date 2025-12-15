/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:27:14 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 11:27:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_string.h"

int			fill_obj_plane(t_object *ptr_obj_tmp, char **elements,
				char **ptr_str_err_msg);
static int	plane_wrong_nb_of_args(char **ptr_str_err_msg);

/* to check
 *	wrong nb args : DONE -> OK !
*	plane_wrong_nb_of_args : DONE -> OK !
*	fill_colors fail : DONE -> OK !
*	fill_coordinates fail : DONE -> OK !
*	fill direction fail : DONE -> OK !
*/

int	fill_obj_plane(t_object *ptr_obj_tmp, char **elements,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_PLANE;
	if (elements[1] == NULL || elements [2] == NULL
		|| elements [3] == NULL || elements [4] != NULL)
		return (plane_wrong_nb_of_args(ptr_str_err_msg));
	ret = fill_colors(&ptr_obj_tmp->object_attr.plane.color.rgba,
			elements[3], ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Plane colors:\n", ret, ptr_str_err_msg));
	ret = fill_coordinates(&ptr_obj_tmp->coordinates, elements[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Plane coordinates:\n", ret, ptr_str_err_msg));
	ret = fill_direction(&ptr_obj_tmp->object_attr.plane.direction,
			elements[2], ptr_str_err_msg);
	if (ret != SUCCESS)
	{
		return (fail_add_msg("Plane direction:\n", ret, ptr_str_err_msg));
	}
	fill_plane_coef(ptr_obj_tmp);
	return (SUCCESS);
}

static int	plane_wrong_nb_of_args(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strdup(MSG_PLANE_WRONG_ARGUMENTS);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}
