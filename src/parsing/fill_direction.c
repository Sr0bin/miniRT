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
#include "ft_string.h"
#include "ft_vectors.h"
#include "minirt.h"
#include "vector.h"

int			fill_direction(t_vec3 **ptr_to_ptr_direction,
				const char *direction, char **ptr_str_err_msg);
static int	fill_from_splitted_direction(t_vec3 **ptr_to_ptr_direction,
				char **splitted_direction, char **ptr_str_err_msg);

int	fill_direction(t_vec3 **ptr_to_ptr_direction, const char *direction,
		char **ptr_str_err_msg)
{
	char	**splitted_direction;
	int		ret;

	splitted_direction = ft_split(direction, ",");
	if (splitted_direction == NULL)
		return (FAILURE_MALLOC);
	ret = fill_from_splitted_direction(ptr_to_ptr_direction,
			splitted_direction, ptr_str_err_msg);
	if (ret == FAILURE_PARSE_PERSONNALIZED)
	{
		*ptr_str_err_msg = ft_strjoin_free_second("[DIRECTION VALUES] : ", *ptr_str_err_msg);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
	}
	ft_split_free(splitted_direction);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

static int	fill_from_splitted_direction(t_vec3 **ptr_to_ptr_direction,
				char **splitted_direction, char **ptr_str_err_msg)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;
	int		ret;

	if (splitted_direction[0] == NULL || splitted_direction[1] == NULL
		|| splitted_direction[2] == NULL || splitted_direction[3] != NULL)
	{
		*ptr_str_err_msg = ft_strdup("wrong number of values to convert, "
			"must take 3 numbers separated by spaces\n");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_DIRECTION_WRONG_FORMAT);
	}
	ret = ft_atof_safe(splitted_direction[0], &tmp_x);
	if (ret != 0)
	{
		*ptr_str_err_msg = ft_strdup("could not convert [value[0]] ");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	}
	ret = ft_atof_safe(splitted_direction[1], &tmp_y);
	if (ret != 0)
	{
		*ptr_str_err_msg = ft_strdup("could not convert [value[1]] ");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	}
	ret = ft_atof_safe(splitted_direction[2], &tmp_z);
	if (ret != 0)
	{
		*ptr_str_err_msg = ft_strdup("could not convert [value[2]] ");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_DIRECTION_ATOF_FAIL);
	}
	if (fabs(sqrt(tmp_x * tmp_x + tmp_y * tmp_y + tmp_z * tmp_z) - 1.0) > 1e-5)
	{
		*ptr_str_err_msg = ft_strdup("value are not normalized ! ");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_DIRECTION_WRONG_VALUE);
	}
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
