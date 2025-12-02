/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_canvas_point_arrays_distance_variation.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:24:58 by jweber            #+#    #+#             */
/*   Updated: 2025/11/27 14:51:16 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graphics.h"
#include "render.h"

void	fill_canvas_point_arrays_distance_variation(
			double (*canvas_point_arrays)[3], double horizontal_fov)
{
	size_t	x_i;
	size_t	y_i;
	double	horizontal_range;
	double	vertical_range;
	double	step;

	horizontal_range = tan(horizontal_fov / 2.0 * M_PI / 180.0) * 2.0;
	step = horizontal_range / (((double)WINDOW_WIDTH) - 1.0);
	vertical_range = step * ((WINDOW_HEIGHT - 1));
	x_i = 0;
	while (x_i < WINDOW_WIDTH)
	{
		y_i = 0;
		while (y_i < WINDOW_HEIGHT)
		{
			canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][0] = 1;
			canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][1]
				= vertical_range / 2.0 - (double)y_i * step;
			canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][2]
				= horizontal_range / 2.0 - (double)x_i * step;
			y_i++;
		}
		x_i++;
	}
	printf("%f\n", canvas_point_arrays[0][X]);
	return ;
}
