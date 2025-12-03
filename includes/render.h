/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:56:09 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 20:10:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "ray.h"
# include "graphics.h"

#define M_PI		3.14159265358979323846	/* pi */

int		render(t_vector objects, t_ray **ptr_array_ray, t_mlx mlx);
int		prepare_rays(t_ray **ptr_array_rays, double horizontal_fov,
			t_object *camera);
void	free_rays(t_ray **ptr_array_rays, size_t nb_rays);
void	fill_canvas_point_arrays_distance_variation(
			t_point3 (*canvas_point_arrays), double horizontal_fov);
void	fill_canvas_point_arrays_angle_variation(
			double (*canvas_point_arrays)[3], double horizontal_fov);
void	normalize_canvas_point_array(t_point3 (*canvas_point_array),
			size_t	nb_rays);
void	rotate_canvas_point_array(t_vec3 (*canvas_point_array),
			size_t nb_rays, t_vec3 direction);
void	rotate_double3(double arr[3], double r[3][3]);
void	set_rotation_matrix(t_mat3 *rotation_matrix, double theta, int axis);

int		test_intersection_jules(t_ray *ray_array, size_t nb_rays,
			t_color *pixel_array, t_vector objects);

#endif
