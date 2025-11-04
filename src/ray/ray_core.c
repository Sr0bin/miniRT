/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:43:02 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/28 16:00:54 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	create_ray(t_point *origin, t_vec3 *direction)
{
	t_ray ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.color.color = 0;
	return (ray);
}

