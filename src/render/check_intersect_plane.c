/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_plane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 15:03:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "render.h"
#include <stdio.h>

// function check if a ray intersect with a plane
// return :
//	- TRUE : if it intersect with the sphere
//			and set intersect point to the closer point it intersect
//			(for smaller 't' of course)
//	- FALSE : if it does not intersect with a sphere
int	check_intersect_plane(t_ray ray, t_object plane,
		double intersect_point[3])
{
	double	t;
	double	denom;
	double	d[3];
	double	p[3];

	d[X] = vector_get_coord(*ray.direction, X);
	d[Y] = vector_get_coord(*ray.direction, Y);
	d[Z] = vector_get_coord(*ray.direction, Z);
	p[X] = point_get_coord(*ray.start, X);
	p[Y] = point_get_coord(*ray.start, Y);
	p[Z] = point_get_coord(*ray.start, Z);
	// algo here 
	/*
	printf("plane.object_attr.plane.a = %f\n", plane.object_attr.plane.a);
	printf("plane.object_attr.plane.b = %f\n", plane.object_attr.plane.b);
	printf("plane.object_attr.plane.c = %f\n", plane.object_attr.plane.c);
	printf("plane.object_attr.plane.d = %f\n", plane.object_attr.plane.d);
	*/
	denom = plane.object_attr.plane.a * d[X]
		+ plane.object_attr.plane.b * d[Y]
		+ plane.object_attr.plane.c * d[Z];
	if (fabs(denom - 0) < 1e-5)
		return (FALSE);
	t = (-plane.object_attr.plane.d
			- plane.object_attr.plane.a * p[X]
			- plane.object_attr.plane.b * p[Y]
			- plane.object_attr.plane.c * p[Z])
		/ denom;
	if (t < 0)
		return (FALSE);
	intersect_point[X] = p[X] + t * d[X];
	intersect_point[Y] = p[Y] + t * d[Y];
	intersect_point[Z] = p[Z] + t * d[Z];
	return (TRUE);
}
