/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:19:31 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 16:31:00 by jweber           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "ray.h"
#include "graphics.h"
#include "render.h"

int	render(t_vector objects, t_ray **ptr_array_ray, t_mlx mlx)
{
	ret = init_rays(&array_ray, 70,
		&((t_object *)objects.data)[OBJ_CAMERA].ptr_coordinates);
	return ;
}
