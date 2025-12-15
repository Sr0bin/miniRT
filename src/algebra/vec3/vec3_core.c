/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:34 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 11:45:26 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "minirt.h"

t_vec3	vec3_scale(t_vec3 vector, double scalar)
{
	t_vec3	temp_vec;
	t_axis	axis;
	double	temp_value;

	axis = X;
	temp_value = 0;
	while (axis < AXIS_THREE)
	{
		temp_value = vec3_get(vector, axis) * scalar;
		vec3_set(&temp_vec, axis, temp_value);
		axis++;
	}
	return (temp_vec);
}

void	*free_vec3(t_vec3 *vector)
{
	free(vector);
	return (NULL);
}
