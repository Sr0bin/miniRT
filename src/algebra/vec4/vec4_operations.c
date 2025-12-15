/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:04:01 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 12:41:35 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec4.h"

double	vector_norm4(t_vec4 a)
{
	t_axis	axis;
	double	sum;

	axis = X;
	sum = 0;
	while (axis < AXIS_FOUR)
	{
		sum += pow(vec4_get(a, axis), 2);
		axis++;
	}
	return (sqrt(sum));
}

t_vec4	vec4_add(t_vec4 a, t_vec4 b)
{
	t_vec4	temp_vec;
	t_axis	axis;
	double	temp_value;

	axis = X;
	temp_value = 0;
	while (axis < AXIS_FOUR)
	{
		temp_value = vec4_get(a, axis) + vec4_get(b, axis);
		vec4_set(&temp_vec, axis, temp_value);
		axis++;
	}
	return (temp_vec);
}

t_vec4	vec4_subtract(t_vec4 a, t_vec4 b)
{
	t_vec4	temp_vec;
	t_axis	axis;
	double	temp_value;

	axis = X;
	temp_value = 0;
	while (axis < AXIS_FOUR)
	{
		temp_value = vec4_get(a, axis) - vec4_get(b, axis);
		vec4_set(&temp_vec, axis, temp_value);
		axis++;
	}
	return (temp_vec);
}

void	normalize_vec4(t_vec4	*vector)
{
	*vector = vec4_scale(*vector, 1 / vector_norm4(*vector));
}
