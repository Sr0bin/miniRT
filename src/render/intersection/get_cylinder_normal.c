/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinder_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:23:07 by jweber            #+#    #+#             */
/*   Updated: 2025/12/12 14:47:56 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

void	get_cylinder_normal_ext(t_intersect *ptr_intersect_data,
			t_vec3 intersect_point_no_x, t_object cylinder)
{
	t_mat3	r;
	double	angle;

	ptr_intersect_data->normal = intersect_point_no_x;
	normalize_vec3(&ptr_intersect_data->normal);
	if (get_r_cylinder_to_tmp_frame(&r,
			cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal,
				r);
	}
	if (get_r_tmp_to_world_frame(&r,
			cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal,
				r);
	}
}

void	get_cylinder_normal_int(t_intersect *ptr_intersect_data,
			t_vec3 intersect_point_no_x, t_object cylinder)
{
	t_mat3	r;
	double	angle;

	ptr_intersect_data->normal = vec3_scale(intersect_point_no_x, -1);
	normalize_vec3(&ptr_intersect_data->normal);
	if (get_r_cylinder_to_tmp_frame(&r,
			cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal,
				r);
	}
	if (get_r_tmp_to_world_frame(&r,
			cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal,
				r);
	}
}
