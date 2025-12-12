/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_two_positive_solution.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:22:11 by jweber            #+#    #+#             */
/*   Updated: 2025/12/12 14:38:48 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	cylinder_two_positive_solutions(t_polynomial poly, t_intersect_cylinder cyl_inter,
			t_intersect *ptr_intersect_data_tmp, t_ray ray)
{
	double		x1;
	double		x2;
	t_object	cylinder;

	cylinder = *ptr_intersect_data_tmp->ptr_obj;
	x1 = cyl_inter.ray_transformed.ptr_origin->x + poly.t1 * cyl_inter.ray_transformed.direction.x;
	x2 = cyl_inter.ray_transformed.ptr_origin->x + poly.t2 * cyl_inter.ray_transformed.direction.x;
	if (-cylinder.object_attr.cylinder.height / 2 <= x1 && x1 <= cylinder.object_attr.cylinder.height / 2
		&& -cylinder.object_attr.cylinder.height / 2 <= x2 && x2 <= cylinder.object_attr.cylinder.height / 2)
	{
		ptr_intersect_data_tmp->distance = fmin(poly.t1, poly.t2);
		ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
				vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
		cyl_inter.intersect_point_transformed_no_x = vec3_add(*cyl_inter.ray_transformed_no_x.ptr_origin, vec3_scale(cyl_inter.ray_transformed_no_x.direction, ptr_intersect_data_tmp->distance));
		get_cylinder_normal_ext(ptr_intersect_data_tmp, cyl_inter.intersect_point_transformed_no_x, cylinder);
		return (TRUE);
	}
	else if (-cylinder.object_attr.cylinder.height / 2 <= x1 && x1 <= cylinder.object_attr.cylinder.height / 2)
	{
		ptr_intersect_data_tmp->distance = poly.t1;
		ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
				vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
		cyl_inter.intersect_point_transformed_no_x = vec3_add(*cyl_inter.ray_transformed_no_x.ptr_origin, vec3_scale(cyl_inter.ray_transformed_no_x.direction, ptr_intersect_data_tmp->distance));
		if (fabs(ptr_intersect_data_tmp->distance - fmin(poly.t1,poly.t2)) < 1e-5)
			get_cylinder_normal_ext(ptr_intersect_data_tmp, cyl_inter.intersect_point_transformed_no_x, cylinder);
		else
			get_cylinder_normal_int(ptr_intersect_data_tmp, cyl_inter.intersect_point_transformed_no_x, cylinder);
		return (TRUE);
	}
	else if (-cylinder.object_attr.cylinder.height / 2 <= x2 && x2 <= cylinder.object_attr.cylinder.height / 2)
	{
		ptr_intersect_data_tmp->distance = poly.t2;
		cyl_inter.intersect_point_transformed_no_x = vec3_add(*cyl_inter.ray_transformed_no_x.ptr_origin, vec3_scale(cyl_inter.ray_transformed_no_x.direction, ptr_intersect_data_tmp->distance));
		ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
				vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
		if (fabs(ptr_intersect_data_tmp->distance - fmin(poly.t1,poly.t2)) < 1e-5)
			get_cylinder_normal_ext(ptr_intersect_data_tmp, cyl_inter.intersect_point_transformed_no_x, cylinder);
		else
			get_cylinder_normal_int(ptr_intersect_data_tmp, cyl_inter.intersect_point_transformed_no_x, cylinder);
		return (TRUE);
	}
	else
		return (FALSE);
}
