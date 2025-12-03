/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:23:49 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 17:23:54 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_vectors.h"
#include "minirt.h"
#include "vec3.h"

int	print_objects(t_vector objects);
int	print_ambient(t_object obj);
int	print_camera(t_object obj);
int	print_light(t_object obj);
int	print_sphere(t_object obj);
int	print_plane(t_object obj);
int	print_cylinder(t_object obj);

int	print_objects(t_vector objects)
{
	size_t		i;
	t_object	obj;

	i = 0;
	while (i < objects.size)
	{
		obj = ((t_object *)objects.data)[i];
		if (obj.type == OBJ_AMBIENT)
			print_ambient(obj);
		if (obj.type == OBJ_CAMERA)
			print_camera(obj);
		if (obj.type == OBJ_LIGHT)
			print_light(obj);
		if (obj.type == OBJ_SPHERE)
			print_sphere(obj);
		if (obj.type == OBJ_PLANE)
			print_plane(obj);
		if (obj.type == OBJ_CYLINDER)
			print_cylinder(obj);
		i++;
	}
	return (0);
}

int	print_ambient(t_object obj)
{
	printf("ambient : \n");
	printf("ambient ratio : %f\n", obj.object_attr.ambient.ratio);
	printf("ambient RGB : %i, %i, %i\n",
		obj.object_attr.ambient.color.rgba.red,
		obj.object_attr.ambient.color.rgba.green,
		obj.object_attr.ambient.color.rgba.blue);
	printf("\n");
	return (0);
}

int	print_camera(t_object obj)
{
	printf("camera : \n");
	printf("camera coordinates : %f, %f, %f\n",
		point3_get(obj.ptr_coordinates, X),
		point3_get(obj.ptr_coordinates, Y),
		point3_get(obj.ptr_coordinates, Z));
	printf("camera direction : %f, %f, %f\n",
		vec3_get(obj.object_attr.camera.ptr_direction, X),
		vec3_get(obj.object_attr.camera.ptr_direction, Y),
		vec3_get(obj.object_attr.camera.ptr_direction, Z));
	printf("camera fov : %f\n", obj.object_attr.camera.fov);
	printf("\n");
	return (0);
}

int	print_light(t_object obj)
{
	printf("light\n");
	printf("light coordinates : %f, %f, %f\n",
		point3_get(obj.ptr_coordinates, X),
		point3_get(obj.ptr_coordinates, Y),
		point3_get(obj.ptr_coordinates, Z));
	printf("light brightness ration : %f\n",
		obj.object_attr.light.brightness);
	printf("light RGB : %i, %i, %i\n",
		obj.object_attr.light.color.rgba.red,
		obj.object_attr.light.color.rgba.green,
		obj.object_attr.light.color.rgba.blue);
	printf("\n");
	return (0);
}

int	print_sphere(t_object obj)
{
	printf("sphere : \n");
	printf("sphere coordinates : %f, %f, %f\n",
		point3_get(obj.ptr_coordinates, X),
		point3_get(obj.ptr_coordinates, Y),
		point3_get(obj.ptr_coordinates, Z));
	printf("sphere diameter : %f\n", obj.object_attr.sphere.diameter);
	printf("sphere RGB : %i, %i, %i\n",
		obj.object_attr.sphere.color.rgba.red,
		obj.object_attr.sphere.color.rgba.green,
		obj.object_attr.sphere.color.rgba.blue);
	printf("\n");
	return (0);
}

int	print_plane(t_object obj)
{
	printf("plane coordinates : %f, %f, %f\n",
		point3_get(obj.ptr_coordinates, X),
		point3_get(obj.ptr_coordinates, Y),
		point3_get(obj.ptr_coordinates, Z));
	printf("plane direction : %f, %f, %f\n",
		vec3_get(obj.object_attr.plane.ptr_direction, X),
		vec3_get(obj.object_attr.plane.ptr_direction, Y),
		vec3_get(obj.object_attr.plane.ptr_direction, Z));
	printf("plane coef : a = %f, b = %f, c = %f, d = %f\n",
		obj.object_attr.plane.a,
		obj.object_attr.plane.b,
		obj.object_attr.plane.c,
		obj.object_attr.plane.d);
	printf("plane RGB : %i, %i, %i\n",
		obj.object_attr.plane.color.rgba.red,
		obj.object_attr.plane.color.rgba.green,
		obj.object_attr.plane.color.rgba.blue);
	printf("\n");
	return (0);
}

int	print_cylinder(t_object obj)
{
	printf("cylinder : \n");
	printf("cylinder diameter : %f\n", obj.object_attr.cylinder.diameter);
	printf("cylinder height : %f\n", obj.object_attr.cylinder.height);
	printf("cylinder direction : %f, %f, %f\n",
		vec3_get(obj.object_attr.cylinder.ptr_direction, X),
		vec3_get(obj.object_attr.cylinder.ptr_direction, Y),
		vec3_get(obj.object_attr.cylinder.ptr_direction, Z));
	printf("cylinder RGB : %i, %i, %i\n",
		obj.object_attr.cylinder.color.rgba.red,
		obj.object_attr.cylinder.color.rgba.green,
		obj.object_attr.cylinder.color.rgba.blue);
	printf("\n");
	return (0);
}
