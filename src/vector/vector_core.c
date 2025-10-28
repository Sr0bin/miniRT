/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:34 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/28 15:01:51 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"
#include "minirt.h"

#include <stdio.h>

t_vec3	*create_vector(double x, double y, double z)
{
	t_vec3	*vector;

	vector = create_matrix(4, 1);
	if (vector == NULL)
		return (NULL);
	matrix_set_value(vector, 0, 0, x);
	matrix_set_value(vector, 1, 0, y);
	matrix_set_value(vector, 2, 0, z);
	matrix_set_value(vector, 3, 0, 0);
	return (vector);
}

t_vec3	*vector_copy(t_vec3 vector)
{
	return (create_vector(
		vector_get_coord(vector, X),
		vector_get_coord(vector, Y),
		vector_get_coord(vector, Z)
	));
}
void	vector_set_value(t_vec3 *vector, t_axis axis, double value)
{
	matrix_set_value(vector, axis, 0, value);
}

double	vector_get_coord(t_vec3 vector, t_axis axis)
{
	return (matrix_get_coord(&vector, axis, 0));
}

void	scalar_vector(t_vec3 *vector, double scalar)
{
	scalar_matrix(vector, scalar);
}
void	*free_vector(t_vec3 *vector)
{
	return (free_matrix(vector));
}
