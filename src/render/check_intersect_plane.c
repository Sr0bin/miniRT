/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_plane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:37:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/04 16:05:19 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "point3.h"
#include "ray.h"
#include "render.h"
#include "vec3.h"
#include <stdio.h>

// function check if a ray intersect with a plane
// return :
//	- TRUE : if it intersect with the sphere
//			and set intersect point to the closer point it intersect
//			(for smaller 't' of course)
//	- FALSE : if it does not intersect with a sphere
int	check_intersect_plane(t_ray ray, t_object plane,
		t_intersect *ptr_intersect_data_tmp)
{
	double		t;
	double		denom;
	t_vec3		d;
	t_point3	p;

	d = ray.direction;
	p = *ray.ptr_origin;
	denom = plane.object_attr.plane.a * d.x
		+ plane.object_attr.plane.b * d.y
		+ plane.object_attr.plane.c * d.z;
	if (fabs(denom - 0) < 1e-5)
		return (FALSE);
	t = (-plane.object_attr.plane.d
			- plane.object_attr.plane.a * p.x
			- plane.object_attr.plane.b * p.y
			- plane.object_attr.plane.c * p.z)
		/ denom;
	if (t < 0)
		return (FALSE);
	ptr_intersect_data_tmp->distance = t;
	ptr_intersect_data_tmp->intersect_point.x = p.x + t * d.x;
	ptr_intersect_data_tmp->intersect_point.y = p.y + t * d.y;
	ptr_intersect_data_tmp->intersect_point.z = p.z + t * d.z;
	return (TRUE);
}
