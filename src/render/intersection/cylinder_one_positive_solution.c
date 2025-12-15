/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_one_positive_solution.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:22:29 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 12:15:39 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	cylinder_one_positive_solutions(t_intersect_cylinder cyl_inter,
			t_intersect *ptr_intersect_data_tmp, t_ray ray)
{
	double		x;
	double		t;
	t_object	cylinder;

	cylinder = *ptr_intersect_data_tmp->ptr_obj;
	t = ptr_intersect_data_tmp->distance;
	x = (*cyl_inter.ray_transformed.ptr_origin).x
		+ t * cyl_inter.ray_transformed.direction.x;
	if (-cylinder.object_attr.cylinder.height / 2 <= x
		&& x <= cylinder.object_attr.cylinder.height / 2)
	{
		cyl_inter.intersect_point_transformed_no_x
			= vec3_add(*cyl_inter.ray_transformed_no_x.ptr_origin,
				vec3_scale(cyl_inter.ray_transformed_no_x.direction,
					ptr_intersect_data_tmp->distance));
		ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
				vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
		get_cylinder_normal_int(ptr_intersect_data_tmp,
			cyl_inter.intersect_point_transformed_no_x, cylinder);
		return (TRUE);
	}
	return (FALSE);
}
