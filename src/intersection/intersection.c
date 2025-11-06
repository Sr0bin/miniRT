/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:03:52 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/06 18:29:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "ft_vectors.h"
#include "point.h"
#include "ray.h"
#include "minirt.h"
#include "vector.h"

int	intersection_sphere(t_ray ray, t_object sphere)
{
	t_point	*point;
	double	delta;
	double	a;
	double	b;
	double	c;
	t_vec3	*origin_center;

	origin_center = vector_points(ray.origin, sphere.ptr_coordinates);
	if (origin_center == NULL)
		return (ERROR_MALLOC);
	a = dot_product(*ray.direction, *ray.direction);
	b = 2 * dot_product(*ray.direction, *origin_center);
	c = dot_product(*origin_center, *origin_center)
		- (pow((sphere.object_attr.sphere.diameter) / 2, 2));
	free_vector(origin_center);
	delta = (b * b) - (4 * a * c);
	printf("Delta : %f", delta);
	return (0);
}
//
// t_point	*intersection_check(t_ray ray, t_object obj)
// {
// 	t_point	*point;
//
// 	return (point);
// }
