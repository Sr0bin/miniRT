/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point4_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:29:02 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 12:47:21 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point4.h"
#include "vec4.h"

t_point4	*point4_alloc(double x, double y, double z)
{
	return (vec4_alloc(x, y, z, 1));
}

double	point4_get(t_point4 point, t_axis axis)
{
	return (vec4_get(point, axis));
}

void	point4_set(t_point4 *point, t_axis axis, double value)
{
	vec4_set(point, axis, value);
}

void	*free_point4(t_point4 *point)
{
	free(point);
	return (NULL);
}
