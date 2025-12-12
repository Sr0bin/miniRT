/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:22:23 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/03 14:48:52 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3.h"
#include "vec3.h"

t_point3	offset_point3(t_point3 point, t_vec3 vector)
{
	return (vec3_add(point, vector));
}

t_vec3	*vec3_alloc_from_point3(t_point3 *point)
{
	t_vec3	*vector;

	vector = vec3_alloc(point3_get(*point, 0),
						point3_get(*point, 1),
						point3_get(*point, 2));
	return (vector);
}

//TODO: rename the functions
t_vec3	vect3_from_point3(t_point3 a, t_point3 b)
{
	return (vec3_subtract(b, a));
}

double	points_distance(t_point3 a, t_point3 b)
{
	return (vec3_norm(vect3_from_point3(a, b)));
}
