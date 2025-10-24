/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_single_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:27:32 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:28:54 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_vectors.h"
#include "minirt.h"

int	fill_single_double(double *ptr_double, const char *str);

int	fill_single_double(double *ptr_double, const char *str)
{
	int	ret;

	ret = ft_atof_safe(str, ptr_double);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_SINGLE_ATOF_FAILED);
	return (SUCCESS);
}
