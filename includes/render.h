/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:32:33 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 12:07:33 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "ray.h"
# include "mlx_setup.h"

# define M_PI 3.14159265358979323846/* pi */
# define GLOBAL_SPECULAR 100

int		render(t_scene *ptr_scene, t_ray **ptr_array_ray, t_mlx mlx);
int		prepare_rays(t_ray **ptr_array_rays, double horizontal_fov,
			t_object *camera);
void	free_rays(t_ray **ptr_array_rays);
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

int		fill_screen(t_ray *ray_array, size_t nb_rays,
			t_color *pixel_array, t_scene *ptr_scene);
int		get_r_world_to_tmp_frame(t_mat3 *r2,
			t_vec3 cam_direction, double *ptr_angle);
int		get_r_tmp_to_cylinder_frame(t_mat3 *r1,
			t_vec3 cyl_direction, double *ptr_angle);
int		get_r_cylinder_to_tmp_frame(t_mat3 *r1,
			t_vec3 cyl_direction, double *ptr_angle);
int		get_r_tmp_to_world_frame(t_mat3 *r2, t_vec3 cam_direction,
			double *ptr_angle);
#endif
