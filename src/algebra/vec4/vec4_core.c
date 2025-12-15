/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:51:23 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 12:42:09 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec4.h"
#include <stdio.h>

t_vec4	*vec4_alloc(double x, double y, double z, double w)
{
	t_vec4	*vector;

	vector = malloc(1 * sizeof(t_vec4));
	if (vector == NULL)
		return (NULL);
	vec4_set(vector, X, x);
	vec4_set(vector, Y, y);
	vec4_set(vector, Z, z);
	vec4_set(vector, W, w);
	return (vector);
}

t_vec4	vec4_set_all(double x, double y, double z, double w)
{
	t_vec4	vector;

	vec4_set(&vector, X, x);
	vec4_set(&vector, Y, y);
	vec4_set(&vector, Z, z);
	vec4_set(&vector, W, w);
	return (vector);
}

void	vec4_set(t_vec4 *vector, t_axis axis, double value)
{
	if (axis == X)
		vector->x = value;
	if (axis == Y)
		vector->y = value;
	if (axis == Z)
		vector->z = value;
	if (axis == W)
		vector->w = value;
}

double	vec4_get(t_vec4 vector, t_axis axis)
{
	if (axis == X)
		return (vector.x);
	if (axis == Y)
		return (vector.y);
	if (axis == Z)
		return (vector.z);
	if (axis == W)
		return (vector.w);
	return (0);
}

t_vec4	vec4_scale(t_vec4 vector, double scalar)
{
	t_vec4	temp_vec;
	t_axis	axis;
	double	temp_value;

	axis = X;
	temp_value = 0;
	while (axis < AXIS_FOUR)
	{
		temp_value = vec4_get(vector, axis) * scalar;
		vec4_set(&temp_vec, axis, temp_value);
		axis++;
	}
	return (temp_vec);
}
