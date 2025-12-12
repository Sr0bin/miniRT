/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:22:33 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 19:19:10 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3.h"
#include "vec3.h"

t_point3	*point3_alloc(double x, double y, double z)
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

t_point3	point3_set_all(double x, double y, double z)
{
	return(vec3_set_all(x, y, z));
}
void	*free_point3(t_point3 *point)
{
	return (free_vec3(point));
}
