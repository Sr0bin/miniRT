/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 14:42:40 by jweber           ###   ########.fr       */
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
		double intersect_point[3])
{
	double a;
	double b;
	double c;
	double d[3];
	double f[3];
	double delta;

	d[X] = vector_get_coord(*ray.direction, X);
	d[Y] = vector_get_coord(*ray.direction, Y);
	d[Z] = vector_get_coord(*ray.direction, Z);
	f[X] = point_get_coord(*ray.start, X) - point_get_coord(*sphere.ptr_coordinates, X);
	f[Y] = point_get_coord(*ray.start, Y) - point_get_coord(*sphere.ptr_coordinates, Y);
	f[Z] = point_get_coord(*ray.start, Z) - point_get_coord(*sphere.ptr_coordinates, Z);
	a = my_dot_product(d, d);
	b = 2 * my_dot_product(d, f);
	c = my_dot_product(f, f) - (sphere.object_attr.sphere.diameter / 2) * (sphere.object_attr.sphere.diameter / 2);
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
			intersect_point[X] = point_get_coord(*ray.start, X) + t * vector_get_coord(*ray.direction, X);
			intersect_point[Y] = point_get_coord(*ray.start, Y) + t * vector_get_coord(*ray.direction, Y);
			intersect_point[Z] = point_get_coord(*ray.start, Z) + t * vector_get_coord(*ray.direction, Z);
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
				intersect_point[X] = point_get_coord(*ray.start, X) + t1 * vector_get_coord(*ray.direction, X);
				intersect_point[Y] = point_get_coord(*ray.start, Y) + t1 * vector_get_coord(*ray.direction, Y);
				intersect_point[Z] = point_get_coord(*ray.start, Z) + t1 * vector_get_coord(*ray.direction, Z);
				return (TRUE);
			}
			else
			{
				intersect_point[X] = point_get_coord(*ray.start, X) + t2 * vector_get_coord(*ray.direction, X);
				intersect_point[Y] = point_get_coord(*ray.start, Y) + t2 * vector_get_coord(*ray.direction, Y);
				intersect_point[Z] = point_get_coord(*ray.start, Z) + t2 * vector_get_coord(*ray.direction, Z);
				return (TRUE);
			}
		}
		else if (t1 > 0)
		{
			intersect_point[X] = point_get_coord(*ray.start, X) + t1 * vector_get_coord(*ray.direction, X);
			intersect_point[Y] = point_get_coord(*ray.start, Y) + t1 * vector_get_coord(*ray.direction, Y);
			intersect_point[Z] = point_get_coord(*ray.start, Z) + t1 * vector_get_coord(*ray.direction, Z);
			return (TRUE);
		}
		else
		{
			intersect_point[X] = point_get_coord(*ray.start, X) + t2 * vector_get_coord(*ray.direction, X);
			intersect_point[Y] = point_get_coord(*ray.start, Y) + t2 * vector_get_coord(*ray.direction, Y);
			intersect_point[Z] = point_get_coord(*ray.start, Z) + t2 * vector_get_coord(*ray.direction, Z);
			return (TRUE);
		}
	}
	return (FALSE);
}
