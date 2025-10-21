/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:27:22 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 16:12:00 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

int	parsing(int argc, char **argv, t_tmp_struct *ptr_tmp_struct)
{
	(void) argv;
	(void) ptr_tmp_struct;
	if (argc != 2)
		return (FAILURE);
	return (SUCCESS);
}
