/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:41:06 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/06 18:04:07 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "minirt.h"

typedef struct s_ray
{
	t_point		*origin;
	t_vec3		*direction;
	t_color		color;	
	t_point		*closest_hit;
	t_object	*object_hit;
}	t_ray;

t_ray	create_ray(t_point *origin, t_vec3 *direction);
#endif

