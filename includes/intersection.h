/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:03:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/04 18:55:48 by rorollin         ###   ########.fr       */
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
void		update_intersect_object(t_ray ray, t_object	*obj, t_intersect *intersect_data);
void	update_closest_intersect(t_intersect *intersect_data, t_intersect *intersect_data_tmp);
void	update_intersect_color(t_intersect	*intersect_data, t_scene *ptr_scene);
#endif

