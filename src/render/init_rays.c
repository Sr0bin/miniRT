/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:46:08 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 10:12:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "graphics.h"
#include "minirt.h"
#include "point.h"
#include "ray.h"
#include "render.h"

static int	create_rays(t_ray **ptr_array_rays, size_t nb_rays,
				double (*canvas_point_arrays)[3], t_point **ptr_ptr_cam_point);
static int	create_ray_content(t_ray *array_rays,
				double (*canvas_point_arrays)[3], t_point **ptr_ptr_cam_point);

int	init_rays(t_ray **ptr_array_rays, double horizontal_fov,
		t_object camera)
{
	size_t	nb_rays;
	double	(*canvas_point_arrays)[3];

	nb_rays = WINDOW_WIDTH * WINDOW_HEIGHT;
	canvas_point_arrays = malloc(nb_rays * sizeof(double [3]));
	if (canvas_point_arrays == NULL)
		return (FAILURE_MALLOC);
	fill_canvas_point_arrays_distance_variation(canvas_point_arrays,
		horizontal_fov);
	normalize_canvas_point_array(canvas_point_arrays, nb_rays);
	rotate_canvas_point_array(canvas_point_arrays, nb_rays,
		camera.object_attr.camera.ptr_direction);
	if (create_rays(ptr_array_rays, nb_rays,
			canvas_point_arrays, &camera.ptr_coordinates) != SUCCESS)
	{
		free(canvas_point_arrays);
		return (FAILURE_MALLOC);
	}
	free(canvas_point_arrays);
	return (SUCCESS);
}

static int	create_rays(t_ray **ptr_array_rays, size_t nb_rays,
				double (*canvas_point_arrays)[3], t_point **ptr_ptr_cam_point)
{
	*ptr_array_rays = ft_calloc(nb_rays, sizeof(t_ray));
	if (ptr_array_rays == NULL)
		return (FAILURE_MALLOC);
	if (create_ray_content(*ptr_array_rays,
			canvas_point_arrays, ptr_ptr_cam_point) != SUCCESS)
	{
		free_rays(ptr_array_rays, nb_rays);
		return (FAILURE_MALLOC);
	}
	return (SUCCESS);
}

static int	create_ray_content(t_ray *array_rays,
				double (*canvas_point_arrays)[3], t_point **ptr_ptr_cam_point)
{
	size_t	x_i;
	size_t	y_i;

	x_i = 0;
	while (x_i < WINDOW_WIDTH)
	{
		y_i = 0;
		while (y_i < WINDOW_HEIGHT)
		{
			array_rays[y_i * WINDOW_WIDTH + x_i].start = *ptr_ptr_cam_point;
			if (array_rays[y_i * WINDOW_WIDTH + x_i].start == NULL)
				return (FAILURE_MALLOC);
			array_rays[y_i * WINDOW_WIDTH + x_i].direction
				= create_vector(
					canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][X],
					canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][Y],
					canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][Z]
					);
			if (array_rays[y_i * WINDOW_WIDTH + x_i].direction == NULL)
				return (FAILURE_MALLOC);
			y_i++;
		}
		x_i++;
	}
	return (SUCCESS);
}
