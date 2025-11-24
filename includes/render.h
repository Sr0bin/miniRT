/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:56:09 by jweber            #+#    #+#             */
/*   Updated: 2025/11/24 17:39:27 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "ray.h"

int		init_rays(t_ray **ptr_array_rays, double horizontal_fov);
void	fill_canvas_point_arrays_distance_variation(
			double (*canvas_point_arrays)[3], double horizontal_fov);

#endif
