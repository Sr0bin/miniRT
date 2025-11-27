/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_canvas_point_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:30:53 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 11:35:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "render.h"

void	normalize_canvas_point_array(double (*canvas_point_array)[3],
			size_t	nb_rays)
{
	size_t	i;
	double	val;

	i = 0;
	while (i < nb_rays)
	{
		val = sqrt(canvas_point_array[i][X] * canvas_point_array[i][X]
				+ canvas_point_array[i][Y] * canvas_point_array[i][Y]
				+ canvas_point_array[i][Z] * canvas_point_array[i][Z]);
		canvas_point_array[i][X] /= val;
		canvas_point_array[i][Y] /= val;
		canvas_point_array[i][Z] /= val;
		i++;
	}
}
