/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:24:56 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 13:50:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ft_io.h"

int	print_error(int error, char *str);

int	print_error(int error, char *str)
{
	ft_putstr_fd("error\n", 2);
	if (error == FAILURE_ARGS_WRONG_NUMBER)
	{
		ft_putstr_fd("wrong number of args\n", 2);
		ft_putstr_fd("usage : ./miniRT map_name.rt\n", 2);
	}
	else if (error == FAILURE_ARGS_MAP_NAME_TOO_LONG)
		ft_putstr_fd("map file name is too long\n", 2);
	else if (error == FAILURE_ARGS_BAD_MAP_NAME)
		ft_putstr_fd("wrong map name, must end with .rt\n", 2);
	else if (error == FAILURE_PARSE_WRONG_OBJ_IDENTIFIER)
		ft_putstr_fd("unknonw object identifier, "
			"chose one between 'A, C, L, sp, pl, cy' \n", 2);
	else if (error == FAILURE_PARSE_PERSONNALIZED)
	{
		if (str != NULL)
			ft_putstr_fd(str, 2);
	}
	else if (error == FAILURE_PARSE_AMBIENT_WRONG_OBJ_NB_OF_INFO)
		ft_putstr_fd("wrong number of parameter for ambient\n", 2);
	else if (error == FAILURE_PARSE_CAMERA_WRONG_OBJ_NB_OF_INFO)
		ft_putstr_fd("wrong number of parameter for camera\n", 2);
	else if (error == FAILURE_PARSE_LIGHT_WRONG_OBJ_NB_OF_INFO)
		ft_putstr_fd("wrong number of parameter for light\n", 2);
	else if (error == FAILURE_PARSE_SPHERE_WRONG_OBJ_NB_OF_INFO)
		ft_putstr_fd("wrong number of parameter for sphere\n", 2);
	else if (error == FAILURE_PARSE_PLANE_WRONG_OBJ_NB_OF_INFO)
		ft_putstr_fd("wrong number of parameter for plane\n", 2);
	else if (error == FAILURE_PARSE_CYLINDER_WRONG_OBJ_NB_OF_INFO)
		ft_putstr_fd("wrong number of parameter for cylinder\n", 2);
	else if (error == FAILURE_PARSE_COLOR_WRONG_FORMAT)
		ft_putstr_fd("error while parsing colors : "
			"wrong colors format, check input values\n", 2);
	else if (error == FAILURE_PARSE_COLOR_ATOI_FAILED)
		ft_putstr_fd("error while parsing colors : "
			"color conversion failed, check input values\n", 2);
	else if (error == FAILURE_PARSE_COO_WRONG_FORMAT)
		ft_putstr_fd("error while parsing coordinates : "
			"wrong coordinates format, check input values\n", 2);
	else if (error == FAILURE_PARSE_COO_ATOF_FAILED)
		ft_putstr_fd("error while parsing coordinates : "
			"coordinates conversion failed, check input values\n", 2);
	else if (error == FAILURE_PARSE_COLOR_WRONG_VALUE)
		ft_putstr_fd("error while parsing colors : "
			"color values must be between 0 and 255 inclusive\n", 2);
	else if (error == FAILURE_PARSE_DIRECTION_WRONG_VALUE)
		ft_putstr_fd("error while parsing direction : "
			"wrong direction values, values for the direction must be "
			"normalized (sqrt(x^2 + y^2 + z^2) must equals 1\n", 2);
	else if (error == FAILURE_PARSE_DIRECTION_WRONG_FORMAT)
		ft_putstr_fd("error while parsing direction : "
			"wrong direction format, check input values\n", 2);
	else if (error == FAILURE_PARSE_DIRECTION_ATOF_FAIL)
		ft_putstr_fd("error while parsing direction : "
			"direction conversion failed, check input values\n", 2);
	free(str);
	return (FAILURE);
}
