/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 17:27:18 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "render.h"

// function check if a ray intersect with a sphere
// return :
//	- TRUE : if it intersect with the sphere
//			and set intersect point to the closer point it intersect
//			(for smaller 't' of course)
//	- FALSE : if it does not intersect with a sphere
int	check_intersect_sphere(t_ray ray, t_object sphere,
		t_point3 *intersect_point)
{
	double a;
	double b;
	double c;
	t_vec3 d;
	t_vec3 f;
	double delta;

	d = ray.direction;
	f = vec3_subtract(*ray.origin, sphere.ptr_coordinates);
	a = dot_product3(d, d);
	b = 2 * dot_product3(d, f);
	c = dot_product3(f, f) - (sphere.object_attr.sphere.diameter / 2) * (sphere.object_attr.sphere.diameter / 2);
	delta = b * b - 4 * a * c;
	/*
	printf("\n");
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	printf("c = %f\n", c);
	printf("delta = %f\n", delta);
	*/
	if (delta < 0)
		return (FALSE);
	else if (fabs(delta - 0) < 1e-5)
	{
		double t = (-b) / (2 * a);
		if (t > 0)
		{
			*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t));
			return (TRUE);
		}
		else
			return (FALSE);
	}
	else
	{
		double t1 = (-b - sqrt(delta)) / (2 * a);
		double t2 = (-b + sqrt(delta)) / (2 * a);
		if (t1 > 0 && t2 > 0)
		{
			if (t1 < t2)
			{
				*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t1));
				return (TRUE);
			}
			else
			{
				*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t2));
				return (TRUE);
			}
		}
		else if (t1 > 0)
		{
			*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t1));
			return (TRUE);
		}
		else
		{
			*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t2));
			return (TRUE);
		}
	}
	return (FALSE);
}
