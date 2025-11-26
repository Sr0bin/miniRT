/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:56:09 by jweber            #+#    #+#             */
/*   Updated: 2025/11/26 11:21:49 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "ray.h"
# include "graphics.h"

#define M_PI		3.14159265358979323846	/* pi */

int		render(t_vector objects, t_ray **ptr_array_ray, t_mlx mlx);
int		prepare_rays(t_ray **ptr_array_rays, double horizontal_fov,
			t_object camera);
void	free_rays(t_ray **ptr_array_rays, size_t nb_rays);
void	fill_canvas_point_arrays_distance_variation(
			double (*canvas_point_arrays)[3], double horizontal_fov);
void	fill_canvas_point_arrays_angle_variation(
			double (*canvas_point_arrays)[3], double horizontal_fov);
void	normalize_canvas_point_array(double (*canvas_point_array)[3],
			size_t	nb_rays);
void	rotate_canvas_point_array(double (*canvas_point_array)[3],
			size_t nb_rays, t_vec3 direction);

#endif
