/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_single_light_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:03:46 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 13:03:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "intersection.h"
#include "point3.h"
#include "color.h"
#include "vec3.h"
#include "object.h"

static int	light_intersect(t_ray temp_ray, t_scene *ptr_scene,
				t_vec3 light_dir);

t_color	object_single_light(t_intersect	*ptr_intersect,
			t_scene *ptr_scene, t_object *light)
{
	double		coeff;
	t_ray		temp_ray;
	t_vec3		light_dir;
	t_point3	offset_point;
	t_color		direct_light;

	offset_point = offset_point3(ptr_intersect->intersect_point,
			vec3_scale(intersect_normal(ptr_intersect), 0.00000000001));
	temp_ray.ptr_origin = &offset_point;
	light_dir = vect3_from_point3(offset_point, light->coordinates);
	temp_ray.direction = light_dir;
	normalize_vec3(&temp_ray.direction);
	if (light_intersect(temp_ray, ptr_scene, light_dir) == FALSE)
		return ((t_color){0});
	coeff = coeff_direct_light(ptr_intersect, light);
	direct_light = multiply_color_coeff(*object_color(ptr_intersect->ptr_obj),
			light->object_attr.light.color, coeff);
	coeff = coeff_specular_light(ptr_intersect, *ptr_intersect->ray, light);
	return (color_add(direct_light,
			dim_color(light->object_attr.light.color, coeff)));
}

static int	light_intersect(t_ray temp_ray, t_scene *ptr_scene,
				t_vec3 light_dir)
{
	t_intersect	inter;

	inter = (t_intersect){0};
	update_intersect_all_object(&temp_ray, ptr_scene->objects.data,
		ptr_scene->objects.size, &inter);
	if (inter.ptr_obj != NULL && inter.distance < vec3_norm(light_dir))
		return (FALSE);
	return (TRUE);
}
