/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane_coef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:18:02 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 17:22:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "point3.h"
#include "vec3.h"

void	fill_plane_coef(t_object *ptr_plane)
{
	ptr_plane->object_attr.plane.a = ptr_plane->object_attr.plane.direction.x;
	ptr_plane->object_attr.plane.b = ptr_plane->object_attr.plane.direction.y;
	ptr_plane->object_attr.plane.c = ptr_plane->object_attr.plane.direction.z;
	ptr_plane->object_attr.plane.d
		= -ptr_plane->object_attr.plane.a * ptr_plane->coordinates.x
		-ptr_plane->object_attr.plane.b * ptr_plane->coordinates.y
		-ptr_plane->object_attr.plane.c * ptr_plane->coordinates.z;
	return ;
}
