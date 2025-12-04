/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/04 20:16:44 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "intersection.h"
#include "render.h"

int	solve_polynomial(t_polynomial *poly, double a, double b, double c)
{
	poly->a = a;
	poly->b = b;
	poly->c = c;
	poly->delta = (poly->b * poly->b) - (4 * poly->a * poly->c);
	if (poly->delta < 0)
		return (0);
	if (fabs(poly->delta - 0) < 1e-5)
	{
		poly->t0 = (-b) / (2 * a);
		return (1);
	}
	poly->t1 = (-b - sqrt(poly->delta)) / (2 * a);
	poly->t2 = (-b + sqrt(poly->delta)) / (2 * a);
	return (2);
}

static int update_intersect_sphere(t_intersect *ptr_intersect_data, t_ray ray, double t)
{
	ptr_intersect_data->intersect_point = vec3_add(*ray.ptr_origin, vec3_scale(ray.direction, t));
	ptr_intersect_data->distance = t;
	return (TRUE);
}

// function check if a ray intersect with a sphere
// return :
//	- TRUE : if it intersect with the sphere
//			and set intersect point to the closer point it intersect
//			(for smaller 't' of course)
//	- FALSE : if it does not intersect with a sphere
int	check_intersect_sphere(t_ray ray, t_object sphere,
		t_intersect *ptr_intersect_data_tmp)
{
	t_polynomial	poly;
	int	ret;
	t_vec3	origin_center;

	origin_center = vec3_subtract(*ray.ptr_origin, sphere.coordinates);
	ret = solve_polynomial(&poly, dot_product3(ray.direction, ray.direction),
	2 * dot_product3(ray.direction, origin_center),
	dot_product3(origin_center, origin_center) - (sphere.object_attr.sphere.diameter / 2) * (sphere.object_attr.sphere.diameter / 2));
	if (ret == 0)
		return (FALSE);
	if (ret == 1)
		return (update_intersect_sphere(ptr_intersect_data_tmp, ray, poly.t0));
	if (poly.t1 > 0 && poly.t2 > 0)
	{
		if (poly.t1 < poly.t2)
			return (update_intersect_sphere(ptr_intersect_data_tmp, ray, poly.t1));
		return (update_intersect_sphere(ptr_intersect_data_tmp, ray, poly.t2));
	}
	if (poly.t1 > 0)
		return (update_intersect_sphere(ptr_intersect_data_tmp, ray, poly.t1));
	if (poly.t2 > 0)
		return (update_intersect_sphere(ptr_intersect_data_tmp, ray, poly.t2));
	ptr_intersect_data_tmp->ptr_obj = NULL;
	return (FALSE);
}
