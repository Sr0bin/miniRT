/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tangible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:00:27 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/16 15:21:13 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "printing.h"

int	print_sphere(t_object obj)
{
	printf("sphere : \n");
	printf("sphere coordinates : %f, %f, %f\n",
		point3_get(obj.coordinates, X),
		point3_get(obj.coordinates, Y),
		point3_get(obj.coordinates, Z));
	printf("sphere diameter : %f\n", obj.object_attr.sphere.diameter);
	printf("sphere RGB : %i, %i, %i\n",
		obj.object_attr.sphere.color.rgba.red,
		obj.object_attr.sphere.color.rgba.green,
		obj.object_attr.sphere.color.rgba.blue);
	printf("sphere Amb RGB : %i, %i, %i\n",
		obj.object_attr.sphere.amb_color.rgba.red,
		obj.object_attr.sphere.amb_color.rgba.green,
		obj.object_attr.sphere.amb_color.rgba.blue);
	printf("\n");
	return (0);
}

int	print_plane(t_object obj)
{
	printf("plane coordinates : %f, %f, %f\n",
		point3_get(obj.coordinates, X),
		point3_get(obj.coordinates, Y),
		point3_get(obj.coordinates, Z));
	printf("plane direction : %f, %f, %f\n",
		vec3_get(obj.object_attr.plane.direction, X),
		vec3_get(obj.object_attr.plane.direction, Y),
		vec3_get(obj.object_attr.plane.direction, Z));
	printf("plane coef : a = %f, b = %f, c = %f, d = %f\n",
		obj.object_attr.plane.a,
		obj.object_attr.plane.b,
		obj.object_attr.plane.c,
		obj.object_attr.plane.d);
	printf("plane RGB : %i, %i, %i\n",
		obj.object_attr.plane.color.rgba.red,
		obj.object_attr.plane.color.rgba.green,
		obj.object_attr.plane.color.rgba.blue);
	printf("plane Amb RGB : %i, %i, %i\n",
		obj.object_attr.plane.amb_color.rgba.red,
		obj.object_attr.plane.amb_color.rgba.green,
		obj.object_attr.plane.amb_color.rgba.blue);
	printf("\n");
	return (0);
}

int	print_cylinder(t_object obj)
{
	printf("cylinder : \n");
	printf("cylinder diameter : %f\n", obj.object_attr.cylinder.diameter);
	printf("cylinder height : %f\n", obj.object_attr.cylinder.height);
	printf("cylinder direction : %f, %f, %f\n",
		vec3_get(obj.object_attr.cylinder.direction, X),
		vec3_get(obj.object_attr.cylinder.direction, Y),
		vec3_get(obj.object_attr.cylinder.direction, Z));
	printf("cylinder RGB : %i, %i, %i\n",
		obj.object_attr.cylinder.color.rgba.red,
		obj.object_attr.cylinder.color.rgba.green,
		obj.object_attr.cylinder.color.rgba.blue);
	printf("cylinder Amb RGB : %i, %i, %i\n",
		obj.object_attr.cylinder.amb_color.rgba.red,
		obj.object_attr.cylinder.amb_color.rgba.green,
		obj.object_attr.cylinder.amb_color.rgba.blue);
	printf("\n");
	return (0);
}
