/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:43:02 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 11:18:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ft_standard.h"

void	*ray_destroy(t_ray	**ray)
{
	if (ray == NULL || *ray == NULL)
		return (NULL);
	**ray = (t_ray) {0};
	free(*ray);
	*ray = NULL;
	return (NULL);
}

t_ray	*create_ray(t_point3 *origin, t_vec3 direction)
{
	t_ray	*ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	ray->ptr_origin = origin;
	ray->direction = direction;
	ray->color.color = 0;
	ray->last_hit = (t_point3){0};
	return (ray);
}
