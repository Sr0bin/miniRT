/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:49:54 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:09:08 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "minirt.h"

int			fill_direction(t_vec3 *ptr_direction, const char *direction,
				double min, double max);
static int	fill_from_splitted_direction(t_vec3 *ptr_direction,
				char **splitted_direction, double min, double max);

int	fill_direction(t_vec3 *ptr_direction, const char *direction,
		double min, double max)
{
	char	**splitted_direction;
	int		ret;

	splitted_direction = ft_split(direction, ",");
	if (splitted_direction == NULL)
		return (FAILURE_MALLOC);
	ret = fill_from_splitted_direction(ptr_direction, splitted_direction,
			min, max);
	ft_split_free(splitted_direction);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

static int	fill_from_splitted_direction(t_vec3 *ptr_direction,
				char **splitted_direction, double min, double max)
{
	int	ret;

	if (splitted_direction[0] == NULL || splitted_direction[1] == NULL
		|| splitted_direction[2] == NULL || splitted_direction[3] != NULL)
		return (FAILURE_PARSE_DIRECTION_WRONG_FORMAT);
	ret = ft_atof_safe(splitted_direction[0], &ptr_direction->x);
	if (ret != 0)
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	if (ptr_direction->x < min || ptr_direction->x > max)
		return (FAILURE_PARSE_DIRECTION_WRONG_VALUE);
	ret = ft_atof_safe(splitted_direction[1], &ptr_direction->y);
	if (ret != 0)
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	if (ptr_direction->y < min || ptr_direction->y > max)
		return (FAILURE_PARSE_DIRECTION_WRONG_VALUE);
	ret = ft_atof_safe(splitted_direction[2], &ptr_direction->z);
	if (ret != 0)
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	if (ptr_direction->z < min || ptr_direction->z > max)
		return (FAILURE_PARSE_DIRECTION_WRONG_VALUE);
	return (SUCCESS);
}

/*
	char	**splitted_coo;
	int		ret;

	splitted_coo = ft_split(coo, ",");
	if (splitted_coo == NULL)
		return (FAILURE_MALLOC);
	ret = fill_from_splitted_coo(ptr_coo, splitted_coo);
	free(splitted_coo);
	return (ret);
*/
