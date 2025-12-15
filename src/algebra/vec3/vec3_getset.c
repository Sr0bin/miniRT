/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_getset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:44:48 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 12:25:31 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "minirt.h"

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
