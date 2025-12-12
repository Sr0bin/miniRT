/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:03:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 14:46:26 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include "minirt.h"
#include "point3.h"
# include "ray.h"
#include "vec3.h"

typedef struct s_intersect
{
	t_point3	intersect_point;
	t_object	*ptr_obj;
	double		distance;
	t_color		crnt_color;
	t_ray		*ray;
	t_vec3		normal;
}		t_intersect;

typedef struct s_intersect_cylinder
{
	t_point3	origin_transformed;
	t_point3	origin_transformed_no_x;
	t_ray		ray_transformed;
	t_ray		ray_transformed_no_x;
	t_point3	intersect_point_transformed_no_x;
}			t_intersect_cylinder;

typedef struct s_polynomial
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t0;
	double	t1;
	double	t2;
}	t_polynomial;

double	discriminant(double a, double b, double c);
double	intersection_sphere(t_ray ray, t_sphere sphere, t_point3 *intersection);
int		solve_polynomial(t_polynomial *poly, double a, double b, double c);
int		check_intersect_sphere(t_ray ray, t_object sphere,
			t_intersect *ptr_intersect_data_tmp);
int		check_intersect_plane(t_ray ray, t_object plane,
			t_intersect *ptr_intersect_data_tmp);
int		check_intersect_cylinder(t_ray ray, t_object cylinder,
			t_intersect *ptr_intersect_data_tmp);
int		update_intersect_all_object(t_ray *ray, t_object *obj_array,
			size_t count, t_intersect *intersect_data);
void	update_intersect_color(t_intersect	*intersect_data,
			t_scene *ptr_scene);
t_color	object_single_light(t_intersect	*intersect_data, t_scene *scene,
			t_object *light);
double	coeff_direct_light(t_intersect	*intersect_data, t_object *light);
double	coeff_specular_light(t_intersect *ptr_intersect, t_ray ray,
			t_object *ptr_light);
t_vec3	object_normal(t_object *obj, t_intersect *intersect_data);
t_vec3	intersect_normal(t_intersect *intersect_data);
t_vec3	sphere_normal(t_object *obj, t_point3 hit);
t_vec3	plane_normal(t_object *obj, t_intersect *intersect_data);

void	transform_ray(t_ray *ptr_dest_ray, t_ray src_ray, t_object cylinder);
int		cylinder_one_positive_solutions(t_intersect_cylinder cyl_inter,
			t_intersect *ptr_intersect_data_tmp, t_ray ray);
int		cylinder_two_positive_solutions(t_polynomial poly,
			t_intersect_cylinder cyl_inter,
			t_intersect *ptr_intersect_data_tmp, t_ray ray);
void	get_cylinder_normal_int(t_intersect *ptr_intersect_data,
			t_vec3 intersect_point_no_x, t_object cylinder);
void	get_cylinder_normal_ext(t_intersect *ptr_intersect_data,
			t_vec3 intersect_point_no_x, t_object cylinder);
int		get_r_tmp_to_world_frame(t_mat3 *r2, t_vec3 cam_direction,
			double *ptr_angle);
int		get_r_cylinder_to_tmp_frame(t_mat3 *r1, t_vec3 cyl_direction,
			double *ptr_angle);
int		get_r_tmp_to_cylinder_frame(t_mat3 *r1, t_vec3 cyl_direction,
			double *ptr_angle);
int		get_r_world_to_tmp_frame(t_mat3 *r2, t_vec3 cam_direction,
			double *ptr_angle);

#endif
