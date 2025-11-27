/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:45:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/27 18:52:32 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	dot_product(t_vec3 a, t_vec3 b)
{
	t_axis	axis;
	double sum;

	axis = X;
	sum = 0;
	while (axis < AXIS_COUNT)
	{
		sum += vec3_get(a, axis) * vec3_get(b, axis);
		axis++;
	}
	return (sum);
}

double	vector_norm(t_vec3 a)
{
	t_axis	axis;
	double	sum;

	axis = X;
	sum = 0;
	while (axis < AXIS_COUNT)
	{
		sum += pow(vec3_get(a, axis), 2);
		axis++;
	}
	return (sqrt(sum));
}

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	t_vec3	temp_vec;
	t_axis	axis;
	double	temp_value;

	axis = X;
	temp_value = 0;
	while (axis < AXIS_COUNT)
	{
		temp_value = vec3_get(a, axis) + vec3_get(b, axis);
		vec3_set(&temp_vec, axis, temp_value);
		axis++;
	}
	return (temp_vec);
}

t_vec3	vec3_subtract(t_vec3 a, t_vec3 b)
{
	t_vec3	temp_vec;
	t_axis	axis;
	double	temp_value;

	axis = X;
	temp_value = 0;
	while (axis < AXIS_COUNT)
	{
		temp_value = vec3_get(a, axis) - vec3_get(b, axis);
		vec3_set(&temp_vec, axis, temp_value);
		axis++;
	}
	return (temp_vec);
}
/*
* WARNING : Normal needs to be normalized
*/

t_vec3	reflection_vector(t_vec3 incident, t_vec3 normal)
{
	double	dot;
	t_vec3	temp;
	t_vec3	result;

	temp = normal;
	dot = dot_product(incident, normal);
	temp = vec3_scale(temp, (-2 * dot));
	result = vec3_add(incident, temp);
	return (result);
}

void	normalize_vector(t_vec3	*vector)
{
	*vector = vec3_scale(*vector, 1 / vector_norm(*vector));
}

t_vec3	cross_product(t_vec3 a, t_vec3 b)
{
	double x;
	double y;
	double z;
	t_vec3	vector;

	x = (vec3_get(a, Y) * vec3_get(b, Z))
		- (vec3_get(a, Z) * vec3_get(b, Y));
	y = (vec3_get(a, Z) * vec3_get(b, X))
		- (vec3_get(a, X) * vec3_get(b, Z));
	z = (vec3_get(a, X) * vec3_get(b, Y))
		- (vec3_get(a, Y) * vec3_get(b, X));
	vector = vec3_set_all(x, y, z);
	return (vector);
}
