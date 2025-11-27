/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:36:26 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/27 18:57:14 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "vector.h"

t_point3	*create_point(double x, double y, double z)
{
	return (vec3_alloc(x, y, z));
}

double	point3_get(t_point3 point, t_axis axis)
{
	return (vec3_get(point, axis));
}

void	point3_set(t_point3 *point, t_axis axis, double value)
{
	vec3_set(point, axis, value);
}

void	*free_point(t_point3 *point)
{
	return (free_vector(point));
}
