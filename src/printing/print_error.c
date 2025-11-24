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
	ft_putstr_fd("Error\n", 2);
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
	else if (error == FAILURE_OPEN)
		ft_putstr_fd("could not open file\n", 2);
	else if (error == FAILURE_PARSE_WRONG_NB_AMBIENT)
		ft_putstr_fd("Wrong number of Ambient object: configuration file can only have one ambient object\n", 2);
	else if (error == FAILURE_PARSE_WRONG_NB_LIGHT)
		ft_putstr_fd("Wrong number of Light object: configuration file can only have one light object\n", 2);
	else if (error == FAILURE_PARSE_WRONG_NB_CAMERA)
		ft_putstr_fd("Wrong number of Camera object: configuration file can only have one camera object\n", 2);
	else if (error == FAILURE_MLX)
		ft_putstr_fd("MLX failed to init itself\n", 2);
	free(str);
	return (FAILURE);
}
