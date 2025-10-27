/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:49:54 by jweber            #+#    #+#             */
/*   Updated: 2025/10/27 18:53:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "minirt.h"
#include "vector.h"

int			fill_direction(t_vec3 **ptr_to_ptr_direction, const char *direction,
				double min, double max);
static int	fill_from_splitted_direction(t_vec3 **ptr_to_ptr_direction,
				char **splitted_direction, double min, double max);

int	fill_direction(t_vec3 **ptr_to_ptr_direction, const char *direction,
		double min, double max)
{
	char	**splitted_direction;
	int		ret;

	splitted_direction = ft_split(direction, ",");
	if (splitted_direction == NULL)
		return (FAILURE_MALLOC);
	ret = fill_from_splitted_direction(ptr_to_ptr_direction, splitted_direction,
			min, max);
	ft_split_free(splitted_direction);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

static int	fill_from_splitted_direction(t_vec3 **ptr_to_ptr_direction,
				char **splitted_direction, double min, double max)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;
	int		ret;

	if (splitted_direction[0] == NULL || splitted_direction[1] == NULL
		|| splitted_direction[2] == NULL || splitted_direction[3] != NULL)
		return (FAILURE_PARSE_DIRECTION_WRONG_FORMAT);
	ret = ft_atof_safe(splitted_direction[0], &tmp_x);
	if (ret != 0)
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	if (tmp_x < min || tmp_x > max)
		return (FAILURE_PARSE_DIRECTION_WRONG_VALUE);
	ret = ft_atof_safe(splitted_direction[1], &tmp_y);
	if (ret != 0)
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	if (tmp_y < min || tmp_y > max)
		return (FAILURE_PARSE_DIRECTION_WRONG_VALUE);
	ret = ft_atof_safe(splitted_direction[2], &tmp_z);
	if (ret != 0)
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	if (tmp_z < min || tmp_z > max)
		return (FAILURE_PARSE_DIRECTION_WRONG_VALUE);
	*ptr_to_ptr_direction = create_vector(tmp_x, tmp_y, tmp_z);
	if (*ptr_to_ptr_direction == NULL)
		return (FAILURE_MALLOC);
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
