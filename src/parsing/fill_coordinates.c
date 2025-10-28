/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:55:22 by jweber            #+#    #+#             */
/*   Updated: 2025/10/27 18:37:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "minirt.h"
#include "vector.h"

int			fill_coordinates(t_point **ptr_to_ptr_coo, const char *coo);
static int	fill_from_splitted_coo(t_point **ptr_to_ptr_coo,
				char **splitted_coo);

int	fill_coordinates(t_point **ptr_to_ptr_coo, const char *coo)
{
	char	**splitted_coo;
	int		ret;

	splitted_coo = ft_split(coo, ",");
	if (splitted_coo == NULL)
		return (FAILURE_MALLOC);
	ret = fill_from_splitted_coo(ptr_to_ptr_coo, splitted_coo);
	ft_split_free(splitted_coo);
	return (ret);
}

static int	fill_from_splitted_coo(t_point **ptr_to_ptr_coo,
				char **splitted_coo)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;
	int		ret;

	if (splitted_coo[0] == NULL || splitted_coo [1] == NULL
		|| splitted_coo [2] == NULL || splitted_coo[3] != NULL)
		return (FAILURE_PARSE_COLOR_WRONG_FORMAT);
	ret = ft_atof_safe(splitted_coo[0], &tmp_x);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COO_ATOF_FAILED);
	ret = ft_atof_safe(splitted_coo[1], &tmp_y);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COO_ATOF_FAILED);
	ret = ft_atof_safe(splitted_coo[2], &tmp_z);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COO_ATOF_FAILED);
	*ptr_to_ptr_coo = create_vector(tmp_x, tmp_y, tmp_z);
	if (*ptr_to_ptr_coo == NULL)
		return (FAILURE_MALLOC);
	return (SUCCESS);
}
