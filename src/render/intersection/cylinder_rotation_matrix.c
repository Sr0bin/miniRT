/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_rotation_matrix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:32:27 by jweber            #+#    #+#             */
/*   Updated: 2025/12/12 14:33:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "mat3.h"
#include "render.h"

int	get_r_world_to_tmp_frame(t_mat3 *r2, t_vec3 cam_direction, double *ptr_angle)
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

int	get_r_tmp_to_cylinder_frame(t_mat3 *r1, t_vec3 cyl_direction, double *ptr_angle)
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

int	get_r_cylinder_to_tmp_frame(t_mat3 *r1, t_vec3 cyl_direction, double *ptr_angle)
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

int	get_r_tmp_to_world_frame(t_mat3 *r2, t_vec3 cam_direction, double *ptr_angle)
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
