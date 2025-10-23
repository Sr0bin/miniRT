/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:36:26 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 19:09:50 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	*create_point(double x, double y, double z)
{
	t_point	*point;

	point = create_matrix(4, 1);
	if (point == NULL)
		return (NULL);
	matrix_set_value(point, 0, 0, x);
	matrix_set_value(point, 1, 0, y);
	matrix_set_value(point, 2, 0, z);
	matrix_set_value(point, 3, 0, 1);
	return (point);
}

double	point_get_coord(t_point point, size_t i)
{
	return (matrix_get_coord(&point, i, 0));
}

void	*free_point(t_point *point)
{
	return (free_matrix(point));
}
