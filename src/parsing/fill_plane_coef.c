/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plane_coef.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:55:02 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 18:51:36 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "point3.h"
#include "render.h"
#include "vec3.h"

static void	set_x_y_z(t_vec3 *x, t_vec3 *y, t_vec3 *z);
static void	rotate_frame(t_vec3 frame_x, t_vec3 frame_y, 
				t_vec3 frame_z, t_object *ptr_plane);
void	calc_coef(t_object *ptr_plane, t_vec3 point_A, t_vec3 point_B);

void	fill_plane_coef(t_object *ptr_plane)
{
	t_vec3	frame_x;
	t_vec3	frame_y;
	t_vec3	frame_z;
	t_vec3	point_A;
	t_vec3	point_B;

	// step 1 : rotate x, y, z to aligne 'z' of both frame
	set_x_y_z(&frame_x, &frame_y, &frame_z);
	rotate_frame(frame_x, frame_y, frame_z, ptr_plane);
	point_A = vec3_add(frame_x, *ptr_plane->ptr_coordinates);
	point_B = vec3_add(frame_y, *ptr_plane->ptr_coordinates);
	// point_A[X] = frame_x[X] + point3_get(*ptr_plane->ptr_coordinates, X);
	// point_A[Y] = frame_x[Y] + point3_get(*ptr_plane->ptr_coordinates, Y);
	// point_A[Z] = frame_x[Z] + point3_get(*ptr_plane->ptr_coordinates, Z);
	// point_B[X] = frame_y[X] + point3_get(*ptr_plane->ptr_coordinates, X);
	// point_B[Y] = frame_y[Y] + point3_get(*ptr_plane->ptr_coordinates, Y);
	// point_B[Z] = frame_y[Z] + point3_get(*ptr_plane->ptr_coordinates, Z);
	calc_coef(ptr_plane, point_B, point_A);
}

void	calc_coef(t_object *ptr_plane, t_vec3 point_A, t_vec3 point_B)
{

	(void) ptr_plane;
	(void) point_A;
	(void) point_B;
	return ;
}

void	rotate_frame(t_vec3 frame_x, t_vec3 frame_y, 
			t_vec3 frame_z, t_object *ptr_plane)
{
	double	theta;
	t_mat3	mat;
	t_vec3	plane_direction_no_y;
	double	norm_plane_direction_no_y;

	theta = -(M_PI - acos(vec3_get(*ptr_plane->object_attr.plane.ptr_direction, Y)));
	if (fabs(theta - 0) < 1e-5)
	{
		set_rotation_matrix(&mat, theta, X);
		frame_x = vec3_mult_mat3(frame_x, mat);
		frame_y = vec3_mult_mat3(frame_y, mat);
		frame_z = vec3_mult_mat3(frame_z, mat);
	}
	plane_direction_no_y = *(t_vec3 *) ptr_plane->object_attr.plane.ptr_direction;
	plane_direction_no_y.y = 0;
	norm_plane_direction_no_y = vec3_norm(*ptr_plane->object_attr.plane.ptr_direction);
	if (fabs(norm_plane_direction_no_y - 0) > 1e-5)
	{
		theta = acos(vec3_get(*ptr_plane->object_attr.plane.ptr_direction, Z) / norm_plane_direction_no_y);
		if (plane_direction_no_y.x < 0)
			theta = 2 * M_PI - theta;
		set_rotation_matrix(&mat, theta, Y);
		frame_x = vec3_mult_mat3(frame_x, mat);
		frame_y = vec3_mult_mat3(frame_y, mat);
		frame_z = vec3_mult_mat3(frame_z, mat);
	}
	return ;
}

static void	set_x_y_z(t_vec3 *frame_x, t_vec3 *frame_y, t_vec3 *frame_z)
{
	*frame_x = vec3_set_all(1, 0, 0);
	*frame_y = vec3_set_all(0, 1, 0);
	*frame_z = vec3_set_all(0, 0, 1);
}
