/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:24:56 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 15:26:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "printing.h"
#include "ft_io.h"

int	print_error(int error)
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
	return (FAILURE);
}
