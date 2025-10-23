/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:34 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 19:09:31 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

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

void	print_vector(t_vec3 *vector)
{
	print_matrix(vector);
}

double	vector_get_coord(t_vec3 vector, size_t i)
{
	return (matrix_get_coord(&vector, i, 0));
}

void	*free_vector(t_vec3 *vector)
{
	return (free_matrix(vector));
}
