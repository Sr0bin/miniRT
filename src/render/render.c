/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:19:31 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 15:08:06 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "graphics.h"
#include "render.h"

// Prepare_rays : Done OK!

int	render(t_scene *ptr_scene, t_ray **ptr_array_ray, t_mlx mlx)
{
	int	ret;

	ret = prepare_rays(ptr_array_ray, ptr_scene->camera.object_attr.camera.fov,
			&ptr_scene->camera);
	if (ret != 0)
		return (ret);
	fill_screen(*ptr_array_ray, WINDOW_HEIGHT * WINDOW_WIDTH,
		(t_color *)mlx.mlx_img_data, ptr_scene);
	printf("Done render\n");
	return (SUCCESS);
}
