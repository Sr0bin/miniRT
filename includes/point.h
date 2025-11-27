/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:36:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/27 18:54:35 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "matrix.h"
# include "vector.h"

typedef t_vec3 t_point3;

t_point3	*create_point(double x, double y, double z);
double	point3_get(t_point3 point, t_axis axis);
void	point3_set(t_point3 *point, t_axis axis, double value);
t_point3	offset_point(t_point3 point, t_vec3 vector);
t_vec3	*vec3_alloc_from_point3(t_point3 *point);
t_vec3	vect3_from_point3(t_point3 a, t_point3 b);
void	*free_point(t_point3 *point);
#endif
