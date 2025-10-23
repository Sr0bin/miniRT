/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:45:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 18:23:13 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	dot_product(t_vector3 a, t_vector3 b)
{
	size_t	i;
	double sum;

	i = 0;
	sum = 0;
	while (i < a.row_size)
	{
		sum += vector_get_coord(a, i) * vector_get_coord(b, i);
		i++;
	}
	return (sum);
}

double	vector_norm(t_vector3 a)
{
	size_t	i;
	double	sum;

	i = 0;
	sum = 0;
	while (i < a.row_size)
	{
		sum += vector_get_coord(a, i) * vector_get_coord(a, i);
		i++;
	}
	return (sqrt(sum));

}

t_vector3	*cross_product(t_vector3 a, t_vector3 b)
{
	double x;
	double y;
	double z;
	t_vector3	*vector;

	x = (vector_get_coord(a, 1) * vector_get_coord(b, 2))
		- (vector_get_coord(a, 2) * vector_get_coord(b, 1));
	y = (vector_get_coord(a, 0) * vector_get_coord(b, 2))
		- (vector_get_coord(a, 2) * vector_get_coord(b, 0));
	z = (vector_get_coord(a, 0) * vector_get_coord(b, 1))
		- (vector_get_coord(a, 1) * vector_get_coord(b, 0));
	vector = create_vector(x, y, z);
	return (vector);
}
