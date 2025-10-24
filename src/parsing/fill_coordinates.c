/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:55:22 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 14:05:51 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "minirt.h"

int			fill_coordinates(t_point *ptr_coo, const char *coo);
static int	fill_from_splitted_coo(t_point *ptr_point, char **splittted_coo);

int	fill_coordinates(t_point *ptr_coo, const char *coo)
{
	char	**splitted_coo;
	int		ret;

	splitted_coo = ft_split(coo, ",");
	if (splitted_coo == NULL)
		return (FAILURE_MALLOC);
	ret = fill_from_splitted_coo(ptr_coo, splitted_coo);
	ft_split_free(splitted_coo);
	return (ret);
}

static int	fill_from_splitted_coo(t_point *ptr_coo, char **splitted_coo)
{
	double	tmp_coo;
	int		ret;

	if (splitted_coo[0] == NULL || splitted_coo [1] == NULL
		|| splitted_coo [2] == NULL || splitted_coo[3] != NULL)
		return (FAILURE_PARSE_COLOR_WRONG_FORMAT);
	ret = ft_atof_safe(splitted_coo[0], &tmp_coo);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COO_ATOF_FAILED);
	ptr_coo->x = tmp_coo;
	ret = ft_atof_safe(splitted_coo[1], &tmp_coo);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COO_ATOF_FAILED);
	ptr_coo->y = tmp_coo;
	ret = ft_atof_safe(splitted_coo[2], &tmp_coo);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COO_ATOF_FAILED);
	ptr_coo->z = tmp_coo;
	return (SUCCESS);
}
