/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane_coef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:55:02 by jweber            #+#    #+#             */
/*   Updated: 2025/12/01 18:31:34 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "point.h"
#include "render.h"
#include "vector.h"

static void	set_x_y_z(double x[3], double y[3], double z[3]);
static void	rotate_frame(double frame_x[3], double frame_y[3], 
				double frame_z[3], t_object *ptr_plane);
void	calc_coef(t_object *ptr_plane, double point_A[3], double point_B[3]);

void	fill_plane_coef(t_object *ptr_plane)
{
	double	frame_x[3];
	double	frame_y[3];
	double	frame_z[3];
	double	point_A[3];
	double	point_B[3];

	// step 1 : rotate x, y, z to aligne 'z' of both frame
	set_x_y_z(frame_x, frame_y, frame_z);
	rotate_frame(frame_x, frame_y, frame_z, ptr_plane);
	point_A[X] = frame_x[X] + point_get_coord(*ptr_plane->ptr_coordinates, X);
	point_A[Y] = frame_x[Y] + point_get_coord(*ptr_plane->ptr_coordinates, Y);
	point_A[Z] = frame_x[Z] + point_get_coord(*ptr_plane->ptr_coordinates, Z);
	point_B[X] = frame_y[X] + point_get_coord(*ptr_plane->ptr_coordinates, X);
	point_B[Y] = frame_y[Y] + point_get_coord(*ptr_plane->ptr_coordinates, Y);
	point_B[Z] = frame_y[Z] + point_get_coord(*ptr_plane->ptr_coordinates, Z);
	calc_coef(ptr_plane, point_B, point_A);
}

void	calc_coef(t_object *ptr_plane, double point_A[3], double point_B[3])
{

	return ;
}

void	rotate_frame(double frame_x[3], double frame_y[3], 
			double frame_z[3], t_object *ptr_plane)
{
	double	theta;
	double	r[3][3];
	double	plane_direction_no_y[3];
	double	norm_plane_direction_no_y;

	theta = -(M_PI - acos(vector_get_coord(*ptr_plane->object_attr.plane.ptr_direction, Y)));
	if (fabs(theta - 0) < 1e-5)
	{
		set_rotation_matrix(r, theta, X);
		rotate_double3(frame_x, r);
		rotate_double3(frame_y, r);
		rotate_double3(frame_z, r);
	}
	plane_direction_no_y[X] = vector_get_coord(*ptr_plane->object_attr.plane.ptr_direction, X);
	plane_direction_no_y[Y] = 0;
	plane_direction_no_y[Z] = vector_get_coord(*ptr_plane->object_attr.plane.ptr_direction, Z);
	norm_plane_direction_no_y = vector_norm(*ptr_plane->object_attr.plane.ptr_direction);
	if (fabs(norm_plane_direction_no_y - 0) > 1e-5)
	{
		theta = acos(vector_get_coord(*ptr_plane->object_attr.plane.ptr_direction, Z) / norm_plane_direction_no_y);
		if (plane_direction_no_y[X] < 0)
			theta = 2 * M_PI - theta;
		set_rotation_matrix(r, theta, Y);
		rotate_double3(frame_x, r);
		rotate_double3(frame_y, r);
		rotate_double3(frame_z, r);
	}
	return ;
}

static void	set_x_y_z(double frame_x[3], double frame_y[3], double frame_z[3])
{
	frame_x[0] = 1;
	frame_x[1] = 0;
	frame_x[2] = 0;
	frame_y[0] = 0;
	frame_y[1] = 1;
	frame_y[2] = 0;
	frame_z[0] = 0;
	frame_z[1] = 0;
	frame_z[2] = 1;
}
