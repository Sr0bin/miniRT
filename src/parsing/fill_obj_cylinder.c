/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obj_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:45:36 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 15:06:32 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "parsing.h"
#include "minirt.h"
#include "ft_standard.h"
#include "ft_string.h"

int			fill_obj_cylinder(t_object *ptr_obj_tmp, char **elem,
				char **ptr_str_err_msg);
static int	cylinder_wrong_nb_args(char **ptr_str_err_msg);
static int	fill_cyl_height_diam(char **elems,
				char **ptr_str_err_msg, t_object *ptr_obj_tmp);
static int	fill_cyl_height(char **elems,
				char **ptr_str_err_msg, t_object *ptr_obj_tmp);
static int	fill_cyl_diam(char **elems,
				char **ptr_str_err_msg, t_object *ptr_obj_tmp);

/* to check
 *	wrong nb elems : DONE ->OK !
 *	cylinder_wrong_nb_args :  DONE -> OK !
 *	fill_colors fail : DONE -> OK !
 *	fill_coordinates fail : DONE -> OK !
 *	fill_direction fail : DONE -> OK !
*/

int	fill_obj_cylinder(t_object *ptr_obj_tmp, char **elem,
		char **ptr_str_err_msg)
{
	int	ret;

	ptr_obj_tmp->type = OBJ_CYLINDER;
	if (elem[1] == NULL || elem[2] == NULL || elem[3] == NULL || elem[4] == NULL
		|| elem[5] == NULL || elem[6] != NULL)
		return (cylinder_wrong_nb_args(ptr_str_err_msg));
	ret = fill_cyl_height_diam(elem, ptr_str_err_msg, ptr_obj_tmp);
	if (ret != SUCCESS)
		return (ret);
	ret = fill_colors(&ptr_obj_tmp->object_attr.cylinder.color.rgba, elem[5],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Cylinder colors:\n", ret, ptr_str_err_msg));
	ret = fill_coordinates(&ptr_obj_tmp->coordinates, elem[1],
			ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Cylinder coordinates:\n", ret, ptr_str_err_msg));
	ret = fill_direction(&ptr_obj_tmp->object_attr.cylinder.direction,
			elem[2], ptr_str_err_msg);
	if (ret != SUCCESS)
		return (fail_add_msg("Cylinder coordinates:\n", ret, ptr_str_err_msg));
	return (SUCCESS);
}

static int	cylinder_wrong_nb_args(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strdup(MSG_CYLINDER_WRONG_ARGUMENTS);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	fill_cyl_height_diam(char **elems,
				char **ptr_str_err_msg, t_object *ptr_obj_tmp)
{
	int	ret;

	ret = fill_cyl_height(elems, ptr_str_err_msg, ptr_obj_tmp);
	if (ret != SUCCESS)
		return (fail_add_msg("Cylinder height:\n", ret, ptr_str_err_msg));
	ret = fill_cyl_diam(elems, ptr_str_err_msg, ptr_obj_tmp);
	if (ret != SUCCESS)
		return (fail_add_msg("Cylinder diameter:\n", ret, ptr_str_err_msg));
	return (SUCCESS);
}

static int	fill_cyl_height(char **elems,
				char **ptr_str_err_msg, t_object *ptr_obj_tmp)
{
	int	ret;

	ret = ft_atof_safe(elems[3], &ptr_obj_tmp->object_attr.cylinder.diameter);
	if (ret != SUCCESS)
	{
		return (init_msg_atof_failed(ptr_str_err_msg, ret, elems[3]));
	}
	return (SUCCESS);
}

static int	fill_cyl_diam(char **elems,
				char **ptr_str_err_msg, t_object *ptr_obj_tmp)
{
	int	ret;

	ret = ft_atof_safe(elems[4], &ptr_obj_tmp->object_attr.cylinder.height);
	if (ret != SUCCESS)
	{
		return (init_msg_atof_failed(ptr_str_err_msg, ret, elems[4]));
	}
	return (SUCCESS);
}
