/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:43:35 by jweber            #+#    #+#             */
/*   Updated: 2025/12/12 14:45:28 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec3.h"
#include "minirt.h"
#include "intersection.h"

void	transform_ray(t_ray *ptr_dest_ray, t_ray src_ray, t_object cylinder)
{
	t_mat3	r;
	double	angle;

	*ptr_dest_ray->ptr_origin = vec3_subtract(*src_ray.ptr_origin,
			cylinder.coordinates);
	ptr_dest_ray->direction = src_ray.direction;
	ptr_dest_ray->color = src_ray.color;
	ptr_dest_ray->distance_last_hit = src_ray.distance_last_hit;
	ptr_dest_ray->last_hit = src_ray.last_hit;
	if (get_r_world_to_tmp_frame(&r, cylinder.object_attr.cylinder.direction,
			&angle) == 0)
	{
		ptr_dest_ray->direction = vec3_mult_mat3(ptr_dest_ray->direction, r);
		*ptr_dest_ray->ptr_origin = vec3_mult_mat3(*ptr_dest_ray->ptr_origin,
				r);
		ptr_dest_ray->last_hit = vec3_mult_mat3(ptr_dest_ray->last_hit, r);
	}
	if (get_r_tmp_to_cylinder_frame(&r, cylinder.object_attr.cylinder.direction,
			&angle) == 0)
	{
		ptr_dest_ray->direction = vec3_mult_mat3(ptr_dest_ray->direction, r);
		*ptr_dest_ray->ptr_origin = vec3_mult_mat3(*ptr_dest_ray->ptr_origin,
				r);
		ptr_dest_ray->last_hit = vec3_mult_mat3(ptr_dest_ray->last_hit, r);
	}
}
