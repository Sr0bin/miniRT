/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:43:02 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/26 15:41:44 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "ft_standard.h"

void	*ray_destroy(t_ray	**ray)
{
	if (ray == NULL || *ray == NULL)
		return (NULL);
	free_point((*ray)->last_hit);
	**ray = (t_ray) {0};
	free(*ray);
	*ray = NULL;
	return (NULL);
}

t_ray	*create_ray(t_point *origin, t_vec3 *direction)
{
	t_ray *ray;

	ray = ft_calloc(sizeof(t_ray), 1);
	ray->origin = origin;
	ray->direction = direction;
	ray->color.color = 0;
	ray->last_hit = create_point(0,0,0);
	if (ray->last_hit == NULL)
		return (ray_destroy(&ray));
	return (ray);
}

