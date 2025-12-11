/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_cylinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:03:16 by jweber            #+#    #+#             */
/*   Updated: 2025/12/10 13:57:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3.h"
#include "ray.h"
#include "minirt.h"
#include "intersection.h"
#include "render.h"
#include "vec3.h"

void		transform_ray(t_ray *ptr_dest_ray, t_ray src_ray, t_object cylinder);
static int	get_r1(t_mat3 *r1, t_vec3 cyl_direction, double *ptr_angle);
static int	get_r2(t_mat3 *r2, t_vec3 cam_direction, double *ptr_angle);
void	get_normal_int(t_intersect *ptr_intersect_data, t_vec3 intersect_point_no_x, t_object cylinder);
void	get_normal_ext(t_intersect *ptr_intersect_data, t_vec3 intersect_point_no_x, t_object cylinder);
static int	get_r1_back(t_mat3 *r1, t_vec3 cyl_direction, double *ptr_angle);
static int	get_r2_back(t_mat3 *r2, t_vec3 cam_direction, double *ptr_angle);

int	check_intersect_cylinder(t_ray ray, t_object cylinder,
		t_intersect *ptr_intersect_data_tmp)
{
	t_point3	ray_new_origin;
	t_point3	ray_new_origin_no_x;
	t_ray		ray_transformed;
	t_ray		ray_transformed_no_x;
	t_point3	intersect_point_no_x;
	double		a;
	double		b;
	double		c;
	double		delta;

	ray_transformed.ptr_origin = &ray_new_origin;
	transform_ray(&ray_transformed, ray, cylinder);
	ray_new_origin_no_x = ray_new_origin;
	ray_new_origin_no_x.x = 0;
	ray_transformed_no_x.ptr_origin = &ray_new_origin_no_x;
	ray_transformed_no_x.direction = ray_transformed.direction;
	ray_transformed_no_x.direction.x = 0;
	a = dot_product3(ray_transformed_no_x.direction, ray_transformed_no_x.direction);
	b = 2 * dot_product3(ray_transformed_no_x.direction, *ray_transformed_no_x.ptr_origin);
	c = dot_product3(*ray_transformed_no_x.ptr_origin, *ray_transformed_no_x.ptr_origin)
		- (cylinder.object_attr.cylinder.diameter / 2) * (cylinder.object_attr.cylinder.diameter / 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (FALSE);
	else if (delta > 0)
	{
		double	t1 = (-b -sqrt(delta))/(2*a);
		double	t2 = (-b +sqrt(delta))/(2*a);
		double	x1;
		double	x2;
		if (t1 > 0 && t2 > 0)
		{
			x1 = (*ray_transformed.ptr_origin).x + t1 * ray_transformed.direction.x;
			x2 = (*ray_transformed.ptr_origin).x + t2 * ray_transformed.direction.x;
			if (-cylinder.object_attr.cylinder.height / 2 <= x1 && x1 <= cylinder.object_attr.cylinder.height / 2
				&& -cylinder.object_attr.cylinder.height / 2 <= x2 && x2 <= cylinder.object_attr.cylinder.height / 2)
			{
				ptr_intersect_data_tmp->distance = fmin(t1, t2);
				intersect_point_no_x = vec3_add(*ray_transformed_no_x.ptr_origin, vec3_scale(ray_transformed_no_x.direction, 
							ptr_intersect_data_tmp->distance));
				ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
						vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
				get_normal_ext(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				return (TRUE);
			}
			else if (-cylinder.object_attr.cylinder.height / 2 <= x1 && x1 <= cylinder.object_attr.cylinder.height / 2)
			{
				ptr_intersect_data_tmp->distance = t1;
				intersect_point_no_x = vec3_add(*ray_transformed_no_x.ptr_origin, vec3_scale(ray_transformed_no_x.direction, 
							ptr_intersect_data_tmp->distance));
				ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
						vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
				if (fabs(ptr_intersect_data_tmp->distance - fmin(t1,t2)) < 1e-5)
					get_normal_ext(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				else
					get_normal_int(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				return (TRUE);
			}
			else if (-cylinder.object_attr.cylinder.height / 2 <= x2 && x2 <= cylinder.object_attr.cylinder.height / 2)
			{
				ptr_intersect_data_tmp->distance = t2;
				intersect_point_no_x = vec3_add(*ray_transformed_no_x.ptr_origin, vec3_scale(ray_transformed_no_x.direction, 
							ptr_intersect_data_tmp->distance));
				ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
						vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
				if (fabs(ptr_intersect_data_tmp->distance - fmin(t1,t2)) < 1e-5)
					get_normal_ext(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				else
					get_normal_int(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				return (TRUE);
			}
			else
				return (FALSE);
		}
		else if (t1 > 0)
		{
			x1 = (*ray_transformed.ptr_origin).x + t1 * ray_transformed.direction.x;
			if (-cylinder.object_attr.cylinder.height / 2 <= x1 && x1 <= cylinder.object_attr.cylinder.height / 2)
			{
				ptr_intersect_data_tmp->distance = t1;
				intersect_point_no_x = vec3_add(*ray_transformed_no_x.ptr_origin, vec3_scale(ray_transformed_no_x.direction, 
							ptr_intersect_data_tmp->distance));
				ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
						vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
				get_normal_int(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				return (TRUE);
			}
			else
				return (FALSE);
		}
		else if (t2 > 0)
		{
			x2 = (*ray_transformed.ptr_origin).x + t2 * ray_transformed.direction.x;
			if (-cylinder.object_attr.cylinder.height / 2 <= x2 && x2 <= cylinder.object_attr.cylinder.height / 2)
			{
				ptr_intersect_data_tmp->distance = t2;
				intersect_point_no_x = vec3_add(*ray_transformed_no_x.ptr_origin, vec3_scale(ray_transformed_no_x.direction, 
							ptr_intersect_data_tmp->distance));
				ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
						vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
				get_normal_int(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				return (TRUE);
			}
			else
				return (FALSE);
		}
		else
			return (FALSE);
	}
	else
	{
		double	t = -b / (2 * a);
		double	x;
		if (t > 0)
		{
			x = (*ray_transformed.ptr_origin).x + t * ray_transformed.direction.x; 
			if (-cylinder.object_attr.cylinder.height / 2 <= x && x <= cylinder.object_attr.cylinder.height / 2)
			{
				ptr_intersect_data_tmp->distance = t;
				intersect_point_no_x = vec3_add(*ray_transformed_no_x.ptr_origin, vec3_scale(ray_transformed_no_x.direction, 
							ptr_intersect_data_tmp->distance));
				ptr_intersect_data_tmp->intersect_point = vec3_add(*ray.ptr_origin,
						vec3_scale(ray.direction, ptr_intersect_data_tmp->distance));
				get_normal_ext(ptr_intersect_data_tmp, intersect_point_no_x, cylinder);
				return (TRUE);
			}
			else
				return (FALSE);
		}
		return (FALSE);
	}
}

void	get_normal_ext(t_intersect *ptr_intersect_data, t_vec3 intersect_point_no_x, t_object cylinder)
{
	t_mat3	r;
	double	angle;

	ptr_intersect_data->normal = intersect_point_no_x;
	normalize_vec3(&ptr_intersect_data->normal);
	if (get_r1_back(&r, cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal, r);
	}
	if (get_r2_back(&r, cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal, r);
	}
}

void	get_normal_int(t_intersect *ptr_intersect_data, t_vec3 intersect_point_no_x, t_object cylinder)
{
	t_mat3	r;
	double	angle;

	ptr_intersect_data->normal = vec3_scale(intersect_point_no_x, -1);
	normalize_vec3(&ptr_intersect_data->normal);
	if (get_r1_back(&r, cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal, r);
	}
	if (get_r2_back(&r, cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_intersect_data->normal = vec3_mult_mat3(ptr_intersect_data->normal, r);
	}
}

void	transform_ray(t_ray *ptr_dest_ray, t_ray src_ray, t_object cylinder)
{
	t_mat3	r;
	double	angle;

	*ptr_dest_ray->ptr_origin = vec3_subtract(*src_ray.ptr_origin, cylinder.coordinates);
	ptr_dest_ray->direction = src_ray.direction;
	ptr_dest_ray->color = src_ray.color;
	ptr_dest_ray->distance_last_hit = src_ray.distance_last_hit;
	ptr_dest_ray->last_hit = src_ray.last_hit;
	if (get_r2(&r, cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_dest_ray->direction = vec3_mult_mat3(ptr_dest_ray->direction, r);
		*ptr_dest_ray->ptr_origin = vec3_mult_mat3(*ptr_dest_ray->ptr_origin, r);
		ptr_dest_ray->last_hit = vec3_mult_mat3(ptr_dest_ray->last_hit, r);
	}
	if (get_r1(&r, cylinder.object_attr.cylinder.direction, &angle) == 0)
	{
		ptr_dest_ray->direction = vec3_mult_mat3(ptr_dest_ray->direction, r);
		*ptr_dest_ray->ptr_origin = vec3_mult_mat3(*ptr_dest_ray->ptr_origin, r);
		ptr_dest_ray->last_hit = vec3_mult_mat3(ptr_dest_ray->last_hit, r);
	}
}

static int	get_r2(t_mat3 *r2, t_vec3 cam_direction, double *ptr_angle)
{
	t_vec3			cam_direction_no_y;
	double			norm_cam_direction_no_y;
	double			angle;

	cam_direction_no_y = vec3_set_all(vec3_get(cam_direction, X), 0, vec3_get(cam_direction, Z));
	norm_cam_direction_no_y = vec3_norm(cam_direction_no_y);
	if ((norm_cam_direction_no_y - 0) < 1e-5)
		return (1);
	angle = acos(cam_direction_no_y.x / norm_cam_direction_no_y);
	if (cam_direction_no_y.z > 0)
		angle = 2 * M_PI - angle;
	angle = -angle;
	*ptr_angle = angle;
	set_rotation_matrix(r2, angle, Y);
	return (0);
}


static int	get_r1(t_mat3 *r1, t_vec3 cyl_direction, double *ptr_angle)
{
	double			norm_cam_direction;
	double			angle;

	norm_cam_direction = vec3_norm(cyl_direction);
	angle = (M_PI / 2.0)
		- acos(vec3_get(cyl_direction, Y) / norm_cam_direction);
	if ((angle - 0) < 1e-5)
		return (1);
	angle = -angle;
	*ptr_angle = angle;
	set_rotation_matrix(r1, angle, Z);
	return (0);
}

static int	get_r1_back(t_mat3 *r1, t_vec3 cyl_direction, double *ptr_angle)
{
	double			norm_cam_direction;
	double			angle;

	norm_cam_direction = vec3_norm(cyl_direction);
	angle = (M_PI / 2.0)
		- acos(vec3_get(cyl_direction, Y) / norm_cam_direction);
	if ((angle - 0) < 1e-5)
		return (1);
	*ptr_angle = angle;
	set_rotation_matrix(r1, angle, Z);
	return (0);
}

static int	get_r2_back(t_mat3 *r2, t_vec3 cam_direction, double *ptr_angle)
{
	t_vec3			cam_direction_no_y;
	double			norm_cam_direction_no_y;
	double			angle;

	cam_direction_no_y = vec3_set_all(vec3_get(cam_direction, X), 0, vec3_get(cam_direction, Z));
	norm_cam_direction_no_y = vec3_norm(cam_direction_no_y);
	if ((norm_cam_direction_no_y - 0) < 1e-5)
		return (1);
	angle = acos(cam_direction_no_y.x / norm_cam_direction_no_y);
	if (cam_direction_no_y.z > 0)
		angle = 2 * M_PI - angle;
	*ptr_angle = angle;
	set_rotation_matrix(r2, angle, Y);
	return (0);
}
