/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_canvas_point_arrays_angle_variation.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:24:58 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 09:46:49 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graphics.h"
#include "render.h"

#define M_PI		3.14159265358979323846	/* pi */

void	fill_canvas_point_arrays_angle_variation(
			double (*canvas_point_arrays)[3], double horizontal_fov)
{
	size_t	x_i;
	size_t	y_i;
	double	horizontal_angle;
	double	vertical_angle ;
	double	step;

	horizontal_angle = horizontal_fov * M_PI / 180;
	step = horizontal_angle / (((double)WINDOW_WIDTH) - 1.0);
	vertical_angle = step * ((WINDOW_HEIGHT - 1));
	x_i = 0;
	while (x_i < WINDOW_WIDTH)
	{
		y_i = 0;
		while (y_i < WINDOW_HEIGHT)
		{
			canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][X] = 1;
			canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][Y]
				= tan(vertical_angle / 2.0 - (double)y_i * step);
			canvas_point_arrays[y_i * WINDOW_WIDTH + x_i][Z]
				= tan(horizontal_angle / 2.0 - (double)x_i * step);
			y_i++;
		}
		x_i++;
	}
	return ;
}
