/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:46:08 by jweber            #+#    #+#             */
/*   Updated: 2025/11/24 18:00:57 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include "ft_standard.h"
#include "graphics.h"
#include "matrix.h"
#include "minirt.h"
#include "point.h"
#include "ray.h"
#include "render.h"
#include "vector.h"

/*
static int	allocate_rays(t_ray **ptr_array_rays, size_t nb_rays);
static int	allocate_ray_points_directions(t_ray *array_rays, size_t nb_rays);
static void	free_rays(t_ray **ptr_array_rays, size_t nb_rays);
*/

int	init_rays(t_ray **ptr_array_rays, double horizontal_fov)
{
	size_t	nb_rays;
	double	(*canvas_point_arrays)[3];

	nb_rays = WINDOW_WIDTH * WINDOW_HEIGHT;
	canvas_point_arrays = malloc(nb_rays * sizeof(double [3]));
	if (canvas_point_arrays == NULL)
		return (FAILURE_MALLOC);
	(void) ptr_array_rays;
	fill_canvas_point_arrays_distance_variation(canvas_point_arrays,
							horizontal_fov);
	/*
	if (allocate_rays(ptr_array_rays, nb_rays) != SUCCESS)
	{
		free(canvas_point_arrays);
		return (FAILURE_MALLOC);
	}
	*/
	printf("canvas points :\n");
	for (size_t y_i = 0; y_i < WINDOW_HEIGHT; y_i++)
	{
		for (size_t	x_i = 0; x_i < WINDOW_WIDTH; x_i++)
		{
			printf("%f, %f, %f\n",
				canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][0],
				canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][1],
				canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][2]
				);
		}
		printf("\n\n");
	}
	free(canvas_point_arrays);
	return (SUCCESS);
}

/*
static int	allocate_rays(t_ray **ptr_array_rays, size_t nb_rays)
{
	*ptr_array_rays = ft_calloc(nb_rays, sizeof(t_ray));
	if (ptr_array_rays == NULL)
		return (FAILURE_MALLOC);
	if (allocate_ray_points_directions(*ptr_array_rays, nb_rays) != SUCCESS)
	{
		free_rays(ptr_array_rays, nb_rays);
		return (FAILURE_MALLOC);
	}
	return (SUCCESS);
}

static int	allocate_ray_points_directions(t_ray *array_rays, size_t nb_rays)
{
	size_t	i;

	i = 0;
	while (i < nb_rays)
	{
		array_rays[i].start = create_point(0, 0, 0);
		if (array_rays[i].start == NULL)
			return (FAILURE_MALLOC);
		array_rays[i].direction = create_vector(0, 0, 0);
		if (array_rays[i].direction == NULL)
		{
			free_matrix(array_rays[i].start);
			return (FAILURE_MALLOC);
		}
		i++;
	}
	return (SUCCESS);
}

static void	free_rays(t_ray **ptr_array_rays, size_t nb_rays)
{
	size_t	i;

	i = 0;
	while (i < nb_rays)
	{
		if ((*ptr_array_rays)[i].direction != NULL)
		{
			free_matrix((*ptr_array_rays)[i].direction);
			(*ptr_array_rays)[i].direction = NULL;
		}
		if ((*ptr_array_rays)[i].start != NULL)
		{
			free_matrix((*ptr_array_rays)[i].start);
			(*ptr_array_rays)[i].start = NULL;
		}
		i++;
	}
	free(*ptr_array_rays);
	*ptr_array_rays = NULL;
	return ;
}
*/
