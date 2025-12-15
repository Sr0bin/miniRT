/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:24:56 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 11:59:04 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ft_io.h"
#include "parsing.h"

int	print_error(int error, char *str);

int	print_error(int error, char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (error == FAILURE_ARGS_WRONG_NUMBER)
		ft_putstr_fd("wrong number of args\nusage : ./miniRT map_name.rt\n", 2);
	else if (error == FAILURE_ARGS_MAP_NAME_TOO_LONG)
		ft_putstr_fd("map file name is too long\n", 2);
	else if (error == FAILURE_ARGS_BAD_MAP_NAME)
		ft_putstr_fd("wrong map name, must end with .rt\n", 2);
	else if (error == FAILURE_PARSE_WRONG_OBJ_IDENTIFIER)
		ft_putstr_fd("unknonw object identifier, "
			"chose one between 'A, C, L, sp, pl, cy' \n", 2);
	else if (error == FAILURE_PARSE_PERSONNALIZED && str != NULL)
		ft_putstr_fd(str, 2);
	else if (error == FAILURE_OPEN)
		ft_putstr_fd("could not open file\n", 2);
	else if (error == FAILURE_PARSE_WRONG_NB_AMBIENT)
		ft_putstr_fd(MSG_AMBIENT_TOO_MUCH, 2);
	else if (error == FAILURE_PARSE_WRONG_NB_LIGHT)
		ft_putstr_fd(MSG_LIGHT_TOO_MUCH, 2);
	else if (error == FAILURE_PARSE_WRONG_NB_CAMERA)
		ft_putstr_fd(MSG_CAMERA_TOO_MUCH, 2);
	else if (error == FAILURE_MLX)
		ft_putstr_fd("MLX failed to init itself\n", 2);
	free(str);
	return (FAILURE);
}
