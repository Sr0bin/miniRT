/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:01:12 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 19:09:50 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	*offset_point(t_point *point, t_vec3 *vector)
{
	return (add_matrix(point, vector));
}

t_vec3	*vector_from_point(t_point *point)
{
	t_vec3	*vector;

	vector = create_vector(point_get_coord(*point, 0),
						point_get_coord(*point, 1),
						point_get_coord(*point, 2));
	return (vector);
}

//TODO: rename the functions
t_vec3	*vector_points(t_point *a, t_point *b)
{
	t_vec3	*vector;

	vector = create_vector(point_get_coord(*b, 0) - point_get_coord(*a, 0),
						point_get_coord(*b, 1) - point_get_coord(*a, 1),
						point_get_coord(*b, 2) - point_get_coord(*a, 2));
	return (vector);

}
