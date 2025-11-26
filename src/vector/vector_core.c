/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:34 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/26 16:51:07 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"
#include "minirt.h"

#include <stdio.h>

t_vec3	*create_vector(double x, double y, double z)
{
	t_vec3	*vector;

	vector = malloc(1 * sizeof(t_vec3));
	if (vector == NULL)
		return (NULL);
	vector_set_value(vector, X, x);
	vector_set_value(vector, Y, y);
	vector_set_value(vector, Z, z);
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
	if (axis == X)
		vector->x = value;
	if (axis == Y)
		vector->y = value;
	if (axis == Z)
		vector->z = value;
}

double	vector_get_coord(t_vec3 vector, t_axis axis)
{
	if (axis == X)
		return (vector.x);
	if (axis == Y)
		return (vector.y);
	if (axis == Z)
		return (vector.z);
	return (0);
}

void	scalar_vector(t_vec3 *vector, double scalar)
{
	scalar_matrix(vector, scalar);
}
void	*free_vector(t_vec3 *vector)
{
	free(vector);
	return (NULL);
}
