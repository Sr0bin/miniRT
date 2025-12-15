/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect_cylinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:03:16 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 12:15:10 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point3.h"
#include "ray.h"
#include "minirt.h"
#include "intersection.h"
#include "vec3.h"

static void	init_cyl_inter(t_intersect_cylinder *ptr_cyl_inter,
				t_object cylinder, t_ray ray,
				t_polynomial *ptr_poly);
static int	cylinder_delta_positive(t_polynomial poly,
				t_intersect_cylinder cyl_inter,
				t_intersect *ptr_intersect_data_tmp, t_ray ray);

int	check_intersect_cylinder(t_ray ray, t_object cylinder,
		t_intersect *ptr_intersect_data_tmp)
{
	t_intersect_cylinder	cyl_inter;
	t_polynomial			poly;
	double					t;

	init_cyl_inter(&cyl_inter, cylinder, ray, &poly);
	if (poly.delta < 0)
		return (FALSE);
	if (poly.delta > 0)
	{
		return (cylinder_delta_positive(poly, cyl_inter,
				ptr_intersect_data_tmp, ray));
	}
	t = -poly.b / (2 * poly.a);
	if (t > 0)
	{
		ptr_intersect_data_tmp->distance = t;
		return (cylinder_one_positive_solutions(cyl_inter,
				ptr_intersect_data_tmp, ray));
	}
	return (FALSE);
}

static void	init_cyl_inter(t_intersect_cylinder *ptr_cyl_inter,
			t_object cylinder, t_ray ray,
			t_polynomial *ptr_poly)
{
	double	a;
	double	b;
	double	c;

	ptr_cyl_inter->ray_transformed.ptr_origin
		= &ptr_cyl_inter->origin_transformed;
	transform_ray(&ptr_cyl_inter->ray_transformed, ray, cylinder);
	ptr_cyl_inter->origin_transformed_no_x = ptr_cyl_inter->origin_transformed;
	ptr_cyl_inter->origin_transformed_no_x.x = 0;
	ptr_cyl_inter->ray_transformed_no_x.ptr_origin
		= &ptr_cyl_inter->origin_transformed_no_x;
	ptr_cyl_inter->ray_transformed_no_x.direction
		= ptr_cyl_inter->ray_transformed.direction;
	ptr_cyl_inter->ray_transformed_no_x.direction.x = 0;
	a = dot_product3(ptr_cyl_inter->ray_transformed_no_x.direction,
			ptr_cyl_inter->ray_transformed_no_x.direction);
	b = 2 * dot_product3(ptr_cyl_inter->ray_transformed_no_x.direction,
			*ptr_cyl_inter->ray_transformed_no_x.ptr_origin);
	c = dot_product3(*ptr_cyl_inter->ray_transformed_no_x.ptr_origin,
			*ptr_cyl_inter->ray_transformed_no_x.ptr_origin)
		- (cylinder.object_attr.cylinder.diameter / 2)
		* (cylinder.object_attr.cylinder.diameter / 2);
	solve_polynomial(ptr_poly, a, b, c);
}

static int	cylinder_delta_positive(t_polynomial poly,
			t_intersect_cylinder cyl_inter,
			t_intersect *ptr_intersect_data_tmp, t_ray ray)
{
	if (poly.t1 > 0 && poly.t2 > 0)
		return (cylinder_two_positive_solutions(poly,
				cyl_inter, ptr_intersect_data_tmp, ray));
	if (poly.t1 > 0)
	{
		ptr_intersect_data_tmp->distance = poly.t1;
		return (cylinder_one_positive_solutions(cyl_inter,
				ptr_intersect_data_tmp, ray));
	}
	if (poly.t2 > 0)
	{
		ptr_intersect_data_tmp->distance = poly.t2;
		return (cylinder_one_positive_solutions(cyl_inter,
				ptr_intersect_data_tmp, ray));
	}
	return (FALSE);
}
