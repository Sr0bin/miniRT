/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:01:12 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/06 18:12:11 by rorollin         ###   ########.fr       */
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

	vector = create_vector(point_get_coord(*point, X),
						point_get_coord(*point, Y),
						point_get_coord(*point, Z));
	return (vector);
}

//TODO: rename the functions
t_vec3	*vector_points(t_point *a, t_point *b)
{
	t_vec3	*vector;

	vector = create_vector(point_get_coord(*b, X) - point_get_coord(*a, X),
						point_get_coord(*b, Y) - point_get_coord(*a, Y),
						point_get_coord(*b, Z) - point_get_coord(*a, Z));
	return (vector);

}

double	points_distance(t_point *a, t_point *b)
{
	return (sqrt(
		pow((point_get_coord(*b, X) - point_get_coord(*a, X)),2) + 
		pow((point_get_coord(*b, Y) - point_get_coord(*a, Y)),2) + 
		pow((point_get_coord(*b, Z) - point_get_coord(*a, Z)),2)));
}
