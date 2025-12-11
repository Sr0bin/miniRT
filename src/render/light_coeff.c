/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_coeff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:08:27 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/11 18:41:25 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"
#include "intersection.h"
#include "render.h"

double	coeff_direct_light(t_intersect	*ptr_intersect, t_object *ptr_light)
{
	double	temp;
	t_vec3	normal;
	t_vec3	light_dir;

	normal = intersect_normal(ptr_intersect);
	light_dir = vect3_from_point3(ptr_intersect->intersect_point, ptr_light->coordinates);
	temp = dot_product3(normal, light_dir); 
	temp = temp / (vec3_norm(normal) * vec3_norm(light_dir));
	if (temp <= 0)
		return (0);
	return (temp * ptr_light->object_attr.light.brightness);
}

double	coeff_specular_light(t_intersect *ptr_intersect, t_ray ray, t_object *ptr_light)
{
	double	coeff;
	t_vec3	light_dir;
	t_vec3	reflection;
	t_vec3	visibility;
	t_vec3	normal;

	light_dir = vect3_from_point3(ptr_intersect->intersect_point, ptr_light->coordinates);
	normal = intersect_normal(ptr_intersect); 
	reflection = reflection_vector3(light_dir, normal);
	visibility = ray.direction;
	coeff = dot_product3(reflection, visibility);
	if (coeff <= 0)
		return (0);
	coeff = coeff /  ((vec3_norm(reflection) * vec3_norm(visibility)));
	//TODO: make it on a per object basis
	coeff = pow(coeff, GLOBAL_SPECULAR);
	return (coeff);
}
