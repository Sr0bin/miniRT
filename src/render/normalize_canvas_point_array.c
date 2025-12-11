/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_canvas_point_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:30:53 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 16:55:46 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "render.h"

void	normalize_canvas_point_array(t_point3 (*canvas_point_array),
			size_t	nb_rays)
{
	size_t	i;

	i = 0;
	while (i < nb_rays)
	{
		normalize_vec3(&canvas_point_array[i]);
		i++;
	}
}
