/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:34 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/01 22:18:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vec3.h"
#include "minirt.h"

#include <stdio.h>

t_vec3	*vec3_alloc(double x, double y, double z)
{
	t_vec3	*vector;

	vector = malloc(1 * sizeof(t_vec3));
	if (vector == NULL)
		return (NULL);
	vec3_set(vector, X, x);
	vec3_set(vector, Y, y);
	vec3_set(vector, Z, z);
	return (vector);
}

t_vec3	*vect3_copy(t_vec3 vector)
{
	return (vec3_alloc(
		vec3_get(vector, X),
		vec3_get(vector, Y),
		vec3_get(vector, Z)
	));
}
t_vec3	vec3_set_all(double x, double y, double z)
{
	t_vec3	vector;

	vec3_set(&vector, X, x);
	vec3_set(&vector, Y, y);
	vec3_set(&vector, Z, z);
	return (vector);
}
void	vec3_set(t_vec3 *vector, t_axis axis, double value)
{
	if (axis == X)
		vector->x = value;
	if (axis == Y)
		vector->y = value;
	if (axis == Z)
		vector->z = value;
}

double	vec3_get(t_vec3 vector, t_axis axis)
{
	if (axis == X)
		return (vector.x);
	if (axis == Y)
		return (vector.y);
	if (axis == Z)
		return (vector.z);
	return (0);
}

t_vec3	vec3_scale(t_vec3 vector, double scalar)
{
	t_vec3	temp_vec;
	t_axis	axis;
	double	temp_value;

	axis = X;
	temp_value = 0;
	while (axis < AXIS_THREE)
	{
		temp_value = vec3_get(vector, axis) * scalar;
		vec3_set(&temp_vec, axis, temp_value);
		axis++;
	}
	return (temp_vec);
}

void	*free_vec3(t_vec3 *vector)
{
	free(vector);
	return (NULL);
}
