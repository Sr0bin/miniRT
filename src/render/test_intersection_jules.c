/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:53:13 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 19:23:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "point3.h"
#include "ray.h"
#include "vec3.h"
#include "render.h"
#include <math.h>

int		check_intersect_sphere(t_ray ray, t_object sphere,
			t_point3 *intersect_point);
void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_vector objects);
double	my_norm_from_vec(double v[3]);
double	my_dot_product(double v1[3], double v2[3]);

int	test_intersection_jules(t_ray *ray_array, size_t nb_rays,
		t_color *pixel_array, t_vector objects)
{
	size_t	x_i;

	x_i = 0;
	while (x_i < nb_rays)
	{
		//printf("ray %zu, ", x_i);
		set_pixel_color(ray_array[x_i], pixel_array + x_i, objects);
		x_i++;
	}
	return (0);
}

typedef struct s_intersect
{
	t_point3		intersect_point;
	t_object	*ptr_obj;
	double		distance;
} t_intersect;

void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_vector objects)
{
	size_t		obj_i;
	t_object	*obj_array;
	t_intersect	intersect_data;
	double		distance_tmp;
	t_point3		intersect_point_tmp;
	int			ret;

	obj_array = objects.data;
	intersect_data.ptr_obj = NULL;
	intersect_data.intersect_point = point3_set_all(0,0,0);
	intersect_data.distance = 0;
	obj_i = 3;
	while (obj_i < objects.size)
	{
		intersect_point_tmp = point3_set_all(0,0,0);
		if (obj_array[obj_i].type == OBJ_SPHERE)
		{
			ret = check_intersect_sphere(ray, obj_array[obj_i], &intersect_point_tmp);
			if (ret == TRUE)
			{
				if (intersect_data.ptr_obj == NULL)
				{
					intersect_data.intersect_point = intersect_point_tmp;
					// intersect_data.distance = my_norm_from_vec(intersect_data.intersect_point);
					intersect_data.distance = vec3_norm(intersect_data.intersect_point);
					intersect_data.ptr_obj = obj_array + obj_i;
				}
				else
				{
					distance_tmp = vec3_norm(intersect_point_tmp);
					if (distance_tmp < intersect_data.distance)
					{
						intersect_data.intersect_point = intersect_point_tmp;
						intersect_data.distance = distance_tmp;
						intersect_data.ptr_obj = obj_array + obj_i;
					}
				}
			}
		}
		obj_i++;
	}
	if (intersect_data.ptr_obj != NULL)
		ptr_pixel->color = intersect_data.ptr_obj->object_attr.sphere.color.color;
	return ;
}

// function check if a ray intersect with a sphere
// return :
//	- TRUE : if it intersect with the sphere
//			and set intersect point to the closer point it intersect
//			(for smaller 't' of course)
//	- FALSE : if it does not intersect with a sphere
int	check_intersect_sphere(t_ray ray, t_object sphere,
		t_point3 *intersect_point)
{
	double a;
	double b;
	double c;
	t_vec3 d;
	t_vec3 f;
	double delta;

	d = ray.direction;
	f = vec3_subtract(*ray.origin, *sphere.ptr_coordinates);
	a = dot_product3(d, d);
	b = 2 * dot_product3(d, f);
	c = dot_product3(f, f) - (sphere.object_attr.sphere.diameter / 2) * (sphere.object_attr.sphere.diameter / 2);
	delta = b * b - 4 * a * c;
	/*
	printf("\n");
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	printf("c = %f\n", c);
	printf("delta = %f\n", delta);
	*/
	if (delta < 0)
		return (FALSE);
	else if (fabs(delta - 0) < 1e-5)
	{
		double t = (-b) / (2 * a);
		if (t > 0)
		{
			*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t));
			return (TRUE);
		}
		else
			return (FALSE);
	}
	else
	{
		double t1 = (-b - sqrt(delta)) / (2 * a);
		double t2 = (-b + sqrt(delta)) / (2 * a);
		if (t1 > 0 && t2 > 0)
		{
			if (t1 < t2)
			{
				*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t1));
				return (TRUE);
			}
			else
			{
				*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t2));
				return (TRUE);
			}
		}
		else if (t1 > 0)
		{
			*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t1));
			return (TRUE);
		}
		else
		{
			*intersect_point = vec3_add(*ray.origin, vec3_scale(ray.direction, t2));
			return (TRUE);
		}
	}
	return (FALSE);
}

double	my_dot_product(double v1[3], double v2[3])
{
	return (v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

double	my_norm_from_vec(double v[3])
{
	return (sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]));
}
