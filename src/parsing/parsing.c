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

#include "ft_string.h"
#include "minirt.h"
#include "parsing.h"

#define MAP_NAME_MAX_LEN 8192

static int	check_args(int argc, char **argv);

int	parsing(int argc, char **argv, t_tmp_struct *ptr_tmp_struct)
{
	int	ret;

	(void) ptr_tmp_struct;
	ret = check_args(argc, argv);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}

static int	check_args(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		return (FAILURE_ARGS_WRONG_NUMBER);
	if (ft_strlen_safe(argv[1], &len, MAP_NAME_MAX_LEN) != SUCCESS)
		return (FAILURE_ARGS_MAP_NAME_TOO_LONG);
	if (ft_strcmp(argv[1] + len - 3, ".rt") != 0)
		return (FAILURE_ARGS_BAD_MAP_NAME);
	return (SUCCESS);
}
