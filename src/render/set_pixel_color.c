/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intersection_jules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:24:27 by jweber            #+#    #+#             */
/*   Updated: 2025/12/11 20:48:51 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "ray.h"
#include "render.h"
#include "intersection.h"
#include <stdio.h>

static void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_scene *ptr_scene);

int	fill_screen(t_ray *ray_array, size_t nb_rays,
		t_color *pixel_array, t_scene *ptr_scene)
{
	size_t	x_i;

	x_i = 0;
	while (x_i < nb_rays)
	{
		set_pixel_color(ray_array[x_i], pixel_array + x_i, ptr_scene);
		x_i++;
	}
	return (0);
}

static void	set_pixel_color(t_ray ray, t_color *ptr_pixel, t_scene *ptr_scene)
{
	t_object	*obj_array;
	t_intersect	intersect_data;

	obj_array = ptr_scene->objects.data;
	intersect_data = (t_intersect){0};
	intersect_data.crnt_color.color = 0;
	update_intersect_all_object(&ray, obj_array, ptr_scene->objects.size,
		&intersect_data);
	intersect_data.ray = &ray;
	update_intersect_color(&intersect_data, ptr_scene);
	ptr_pixel->color = intersect_data.crnt_color.color;
	return ;
}
