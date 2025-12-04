/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:41:06 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 19:08:38 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "minirt.h"

typedef struct s_ray
{
	t_point3	*origin;
	t_vec3		direction;
	t_color		color;	
	t_point3	last_hit;
	double		distance_last_hit;
}	t_ray;

t_ray	*create_ray(t_point3 *origin, t_vec3 direction);
void	*ray_destroy(t_ray	**ray);
#endif

