/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:27:50 by jweber            #+#    #+#             */
/*   Updated: 2025/10/28 18:14:38 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "minirt.h"
#include "ft_string.h"

#define MAP_NAME_MAX_LEN 8192

int	check_args(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		return (FAILURE_ARGS_WRONG_NUMBER);
	if (ft_strlen_safe(argv[1], &len, MAP_NAME_MAX_LEN) != SUCCESS)
		return (FAILURE_ARGS_MAP_NAME_TOO_LONG);
	if (len <= 2 || ft_strcmp(argv[1] + len - 3, ".rt") != 0)
		return (FAILURE_ARGS_BAD_MAP_NAME);
	return (SUCCESS);
}
