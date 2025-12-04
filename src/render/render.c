/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:19:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/04 13:49:15 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "ray.h"
#include "graphics.h"
#include "vec3.h"
#include "render.h"

int	render(t_scene *ptr_scene, t_ray **ptr_array_ray, t_mlx mlx)
{
	int	ret;

	ret = prepare_rays(ptr_array_ray, 90, &ptr_scene->camera);
	if (ret != 0)
		return (ret);
	test_intersection_jules(*ptr_array_ray, WINDOW_HEIGHT * WINDOW_WIDTH,
		(t_color *)mlx.mlx_img_data, ptr_scene);
	return (SUCCESS);
}
