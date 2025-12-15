/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_algebra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:40:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 12:41:32 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec4.h"

double	dot_product4(t_vec4 a, t_vec4 b)
{
	t_axis	axis;
	double	sum;

	axis = X;
	sum = 0;
	while (axis < AXIS_FOUR)
	{
		sum += vec4_get(a, axis) * vec4_get(b, axis);
		axis++;
	}
	return (sum);
}

/*
* WARNING : Normal needs to be normalized
*/

t_vec4	reflection_vector4(t_vec4 incident, t_vec4 normal)
{
	double	dot;
	t_vec4	temp;
	t_vec4	result;

	temp = normal;
	dot = dot_product4(incident, normal);
	temp = vec4_scale(temp, (-2 * dot));
	result = vec4_add(incident, temp);
	return (result);
}

t_vec4	cross_product4(t_vec4 a, t_vec4 b)
{
	double	x;
	double	y;
	double	z;
	t_vec4	vector;

	x = (vec4_get(a, Y) * vec4_get(b, Z))
		- (vec4_get(a, Z) * vec4_get(b, Y));
	y = (vec4_get(a, Z) * vec4_get(b, X))
		- (vec4_get(a, X) * vec4_get(b, Z));
	z = (vec4_get(a, X) * vec4_get(b, Y))
		- (vec4_get(a, Y) * vec4_get(b, X));
	vector = vec4_set_all(x, y, z, 0);
	return (vector);
}
