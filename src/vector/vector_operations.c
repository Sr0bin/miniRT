/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:45:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/25 13:30:30 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	dot_product(t_vec3 a, t_vec3 b)
{
	t_axis	axis;
	double sum;

	axis = X;
	sum = 0;
	while (axis < a.row_size)
	{
		sum += vector_get_coord(a, axis) * vector_get_coord(b, axis);
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
	while (axis < a.row_size)
	{
		sum += pow(vector_get_coord(a, axis), 2);
		axis++;
	}
	return (sqrt(sum));

}

/*
* WARNING : Normal needs to be normalized
*/

t_vec3	*reflection_vector(t_vec3 incident, t_vec3 normal)
{
	double	dot;
	t_vec3	*temp;
	t_vec3	*result;

	temp = vector_copy(normal);
	if (temp == NULL)
		return (NULL);
	dot = dot_product(incident, normal);
	scalar_vector(temp, (-2 * dot));
	result = add_matrix(&incident, temp);
	free_vector(temp);
	return (result);
}

void	normalize_vector(t_vec3	*vector)
{
	scalar_vector(vector, 1 / vector_norm(*vector));
}

t_vec3	*cross_product(t_vec3 a, t_vec3 b)
{
	double x;
	double y;
	double z;
	t_vec3	*vector;

	x = (vector_get_coord(a, Y) * vector_get_coord(b, Z))
		- (vector_get_coord(a, Z) * vector_get_coord(b, Y));
	y = (vector_get_coord(a, Z) * vector_get_coord(b, X))
		- (vector_get_coord(a, X) * vector_get_coord(b, Z));
	z = (vector_get_coord(a, X) * vector_get_coord(b, Y))
		- (vector_get_coord(a, Y) * vector_get_coord(b, X));
	vector = create_vector(x, y, z);
	return (vector);
}
