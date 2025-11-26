/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:19:31 by jweber            #+#    #+#             */
/*   Updated: 2025/11/26 11:22:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "ray.h"
#include "graphics.h"
#include "render.h"

int	render(t_vector objects, t_ray **ptr_array_ray, t_mlx mlx)
{
	int	ret;

	(void) mlx;
	ret = prepare_rays(ptr_array_ray, 70,
			((t_object *)objects.data)[OBJ_CAMERA]);
	if (ret != 0)
		return (ret);
	//ret = intersect(*ptr_array_ray, mlx); (function which will change
	//every pixel of mlx.img_data (image which will be used to display
	//the scene
	return (SUCCESS);
}
