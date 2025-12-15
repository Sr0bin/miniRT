/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:23:49 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 12:36:28 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_vectors.h"
#include "minirt.h"
#include "vec3.h"
#include "printing.h"

int	print_ambient(t_object obj);
int	print_camera(t_object obj);
int	print_light(t_object obj);

int	print_object(t_object obj)
{
	if (obj.type == OBJ_SPHERE)
		print_sphere(obj);
	if (obj.type == OBJ_PLANE)
		print_plane(obj);
	if (obj.type == OBJ_CYLINDER)
		print_cylinder(obj);
	return (0);
}

int	print_objects(t_scene *ptr_scene)
{
	size_t		i;
	t_object	obj;

	print_ambient(ptr_scene->ambient_light);
	print_camera(ptr_scene->camera);
	i = 0;
	while (i < ptr_scene->lights_arr.size)
	{
		obj = ((t_object *)ptr_scene->lights_arr.data)[i];
		print_light(obj);
		i++;
	}
	i = 0;
	while (i < ptr_scene->objects.size)
	{
		obj = ((t_object *)ptr_scene->objects.data)[i];
		print_object(obj);
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
		point3_get(obj.coordinates, X),
		point3_get(obj.coordinates, Y),
		point3_get(obj.coordinates, Z));
	printf("camera direction : %f, %f, %f\n",
		vec3_get(obj.object_attr.camera.direction, X),
		vec3_get(obj.object_attr.camera.direction, Y),
		vec3_get(obj.object_attr.camera.direction, Z));
	printf("camera fov : %f\n", obj.object_attr.camera.fov);
	printf("\n");
	return (0);
}

int	print_light(t_object obj)
{
	printf("light\n");
	printf("light coordinates : %f, %f, %f\n",
		point3_get(obj.coordinates, X),
		point3_get(obj.coordinates, Y),
		point3_get(obj.coordinates, Z));
	printf("light brightness ration : %f\n",
		obj.object_attr.light.brightness);
	printf("light RGB : %i, %i, %i\n",
		obj.object_attr.light.color.rgba.red,
		obj.object_attr.light.color.rgba.green,
		obj.object_attr.light.color.rgba.blue);
	printf("\n");
	return (0);
}
