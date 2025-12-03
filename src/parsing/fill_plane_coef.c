/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane_coef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:55:02 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 14:59:24 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "point.h"
#include "vector.h"

void	calc_coef(t_object *ptr_plane, double point_A[3], double point_B[3]);

void	fill_plane_coef(t_object *ptr_plane)
{
	ptr_plane->object_attr.plane.a = vector_get_coord(
			*ptr_plane->object_attr.plane.ptr_direction, X);
	ptr_plane->object_attr.plane.b = vector_get_coord(
			*ptr_plane->object_attr.plane.ptr_direction, Y);
	ptr_plane->object_attr.plane.c = vector_get_coord(
			*ptr_plane->object_attr.plane.ptr_direction, Z);
	ptr_plane->object_attr.plane.d
		= -ptr_plane->object_attr.plane.a * point_get_coord(*ptr_plane->ptr_coordinates, X)
		-ptr_plane->object_attr.plane.b * point_get_coord(*ptr_plane->ptr_coordinates, Y)
		-ptr_plane->object_attr.plane.c * point_get_coord(*ptr_plane->ptr_coordinates, Z);
}

void	calc_coef(t_object *ptr_plane, double point_A[3], double point_B[3])
{

	(void) ptr_plane;
	(void) point_A;
	(void) point_B;
	return ;
}
