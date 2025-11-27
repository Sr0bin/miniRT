/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:01:12 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/27 18:54:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point3	offset_point(t_point3 point, t_vec3 vector)
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
