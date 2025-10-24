/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_single_double_range.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:27:32 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 13:46:27 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_vectors.h"
#include "minirt.h"

int	fill_single_double_range(double *ptr_double, const char *str,
		double min, double max);

int	fill_single_double_range(double *ptr_double, const char *str,
		double min, double max)
{
	int	ret;

	ret = ft_atof_safe(str, ptr_double);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_SINGLE_ATOF_FAILED);
	if (*ptr_double < min || *ptr_double > max)
		return (FAILURE_PARSE_SINGLE_WRONG_VALUE);
	return (SUCCESS);
}
