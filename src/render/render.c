/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:19:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 16:06:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "ray.h"
#include "graphics.h"
#include "vec3.h"
#include "render.h"

int	render(t_vector objects, t_ray **ptr_array_ray, t_mlx mlx)
{
	int	ret;

	ret = prepare_rays(ptr_array_ray, 90,
			((t_object *)objects.data)[OBJ_CAMERA]);
	/*
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
	{
		printf("ray[%i]: %f, %f, %f\n", i,
			vector_get_coord(*(*ptr_array_ray)[i].direction,X),
			vector_get_coord(*(*ptr_array_ray)[i].direction,Y),
			vector_get_coord(*(*ptr_array_ray)[i].direction,Z));
	}
	*/
	if (ret != 0)
		return (ret);
	test_intersection_jules(*ptr_array_ray, WINDOW_HEIGHT * WINDOW_WIDTH,
		(t_color *)mlx.mlx_img_data, objects);
	return (SUCCESS);
}
