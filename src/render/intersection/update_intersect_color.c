/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_intersect_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:53:00 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 12:21:08 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "ft_vectors.h"
#include "object.h"
#include "color.h"
#include "minirt.h"

static t_color	object_sum_lights(t_intersect *ptr_intersect,
					t_scene *ptr_scene);

void	update_intersect_color(t_intersect	*ptr_intersect, t_scene *ptr_scene)
{
	if (ptr_intersect->ptr_obj != NULL)
	{
		ptr_intersect->crnt_color = object_ambient_color(ptr_intersect->ptr_obj,
				*ptr_scene);
		ptr_intersect->crnt_color = color_add(ptr_intersect->crnt_color,
				object_sum_lights(ptr_intersect, ptr_scene));
	}
	else
		ptr_intersect->crnt_color.color = BACKGROUND_COLOR;
}

static t_color	object_sum_lights(t_intersect *ptr_intersect,
					t_scene *ptr_scene)
{
	t_color		temp;
	t_object	*crnt_light;
	size_t		i;

	i = 0;
	temp.color = 0;
	while (i < ptr_scene->lights_arr.size)
	{
		crnt_light = &((t_object *)ptr_scene->lights_arr.data)[i];
		temp = color_add(temp, object_single_light(ptr_intersect,
					ptr_scene, crnt_light));
		i++;
	}
	return (temp);
}
