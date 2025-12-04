/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:03:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/04 20:01:06 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include "minirt.h"
# include "ray.h"

typedef struct s_intersect
{
	t_point3	intersect_point;
	t_object	*ptr_obj;
	double		distance;
	t_color		crnt_color;
}		t_intersect;

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
int	solve_polynomial(t_polynomial *poly, double a, double b, double c);
int	check_intersect_sphere(t_ray ray, t_object sphere,
		t_intersect *ptr_intersect_data_tmp);
int		check_intersect_plane(t_ray ray, t_object plane,
			t_intersect *ptr_intersect_data_tmp);
int		update_intersect_object(t_ray ray, t_object	*obj, t_intersect *intersect_data);
int	update_intersect_all_object(t_ray ray, t_object *obj_array, size_t count, t_intersect *intersect_data);
void	update_closest_intersect(t_intersect *intersect_data, t_intersect *intersect_data_tmp);
void	update_intersect_color(t_intersect	*intersect_data, t_scene *ptr_scene);
t_color	object_ambient_color(t_object *obj, t_scene scene);
t_color	multiply_color_coeff(t_color first, t_color second, double coeff);
t_color	object_direct_light(t_intersect	*intersect_data, t_scene *scene, t_object *light);
t_color	object_sum_direct_light(t_intersect *intersect_data, t_scene *scene);
t_color	color_add(t_color a, t_color b);
#endif

