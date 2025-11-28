/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:53:13 by jweber            #+#    #+#             */
/*   Updated: 2025/11/27 16:38:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "point.h"
#include "ray.h"
#include "vector.h"
#include "render.h"
#include <math.h>

int		check_intersect_sphere(t_ray ray, t_object sphere,
			double intersect_point[3]);
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
	double		intersect_point[3];
	t_object	*ptr_obj;
	double		distance;
} t_intersect;

void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_vector objects)
{
	size_t		obj_i;
	t_object	*obj_array;
	t_intersect	intersect_data;
	double		distance_tmp;
	double		intersect_point_tmp[3];
	int			ret;

	obj_array = objects.data;
	intersect_data.ptr_obj = NULL;
	intersect_data.intersect_point[0] = 0;
	intersect_data.intersect_point[1] = 0;
	intersect_data.intersect_point[2] = 0;
	intersect_data.distance = 0;
	obj_i = 3;
	while (obj_i < objects.size)
	{
		intersect_point_tmp[0] = 0;
		intersect_point_tmp[1] = 0;
		intersect_point_tmp[2] = 0;
		if (obj_array[obj_i].type == OBJ_SPHERE)
		{
			ret = check_intersect_sphere(ray, obj_array[obj_i], intersect_point_tmp);
			if (ret == TRUE)
			{
				if (intersect_data.ptr_obj == NULL)
				{
					intersect_data.intersect_point[0] = intersect_point_tmp[0];
					intersect_data.intersect_point[1] = intersect_point_tmp[1];
					intersect_data.intersect_point[2] = intersect_point_tmp[2];
					intersect_data.distance = my_norm_from_vec(intersect_data.intersect_point);
					intersect_data.ptr_obj = obj_array + obj_i;
				}
				else
				{
					distance_tmp = my_norm_from_vec(intersect_point_tmp);
					if (distance_tmp < intersect_data.distance)
					{
						intersect_data.intersect_point[0] = intersect_point_tmp[0];
						intersect_data.intersect_point[1] = intersect_point_tmp[1];
						intersect_data.intersect_point[2] = intersect_point_tmp[2];
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
		double intersect_point[3])
{
	double a;
	double b;
	double c;
	double d[3];
	double f[3];
	double delta;

	d[X] = vector_get_coord(*ray.direction, X);
	d[Y] = vector_get_coord(*ray.direction, Y);
	d[Z] = vector_get_coord(*ray.direction, Z);
	f[X] = point_get_coord(*ray.start, X) - point_get_coord(*sphere.ptr_coordinates, X);
	f[Y] = point_get_coord(*ray.start, Y) - point_get_coord(*sphere.ptr_coordinates, Y);
	f[Z] = point_get_coord(*ray.start, Z) - point_get_coord(*sphere.ptr_coordinates, Z);
	a = my_dot_product(d, d);
	b = 2 * my_dot_product(d, f);
	c = my_dot_product(f, f) - (sphere.object_attr.sphere.diameter / 2) * (sphere.object_attr.sphere.diameter / 2);
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
			intersect_point[X] = point_get_coord(*ray.start, X) + t * vector_get_coord(*ray.direction, X);
			intersect_point[Y] = point_get_coord(*ray.start, Y) + t * vector_get_coord(*ray.direction, Y);
			intersect_point[Z] = point_get_coord(*ray.start, Z) + t * vector_get_coord(*ray.direction, Z);
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
				intersect_point[X] = point_get_coord(*ray.start, X) + t1 * vector_get_coord(*ray.direction, X);
				intersect_point[Y] = point_get_coord(*ray.start, Y) + t1 * vector_get_coord(*ray.direction, Y);
				intersect_point[Z] = point_get_coord(*ray.start, Z) + t1 * vector_get_coord(*ray.direction, Z);
				return (TRUE);
			}
			else
			{
				intersect_point[X] = point_get_coord(*ray.start, X) + t2 * vector_get_coord(*ray.direction, X);
				intersect_point[Y] = point_get_coord(*ray.start, Y) + t2 * vector_get_coord(*ray.direction, Y);
				intersect_point[Z] = point_get_coord(*ray.start, Z) + t2 * vector_get_coord(*ray.direction, Z);
				return (TRUE);
			}
		}
		else if (t1 > 0)
		{
			intersect_point[X] = point_get_coord(*ray.start, X) + t1 * vector_get_coord(*ray.direction, X);
			intersect_point[Y] = point_get_coord(*ray.start, Y) + t1 * vector_get_coord(*ray.direction, Y);
			intersect_point[Z] = point_get_coord(*ray.start, Z) + t1 * vector_get_coord(*ray.direction, Z);
			return (TRUE);
		}
		else
		{
			intersect_point[X] = point_get_coord(*ray.start, X) + t2 * vector_get_coord(*ray.direction, X);
			intersect_point[Y] = point_get_coord(*ray.start, Y) + t2 * vector_get_coord(*ray.direction, Y);
			intersect_point[Z] = point_get_coord(*ray.start, Z) + t2 * vector_get_coord(*ray.direction, Z);
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
