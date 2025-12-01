/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point4.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 03:59:22 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 04:00:24 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT4_H
# define POINT4_H
# include "matrix.h"
# include "vec4.h"

typedef t_vec4 t_point4;

t_point4	*point4_alloc(double x, double y, double z);
double	point4_get(t_point4 point, t_axis axis);
void	point4_set(t_point4 *point, t_axis axis, double value);
t_point4	offset_point4(t_point4 point, t_vec4 vector);
t_vec4	*vec4_alloc_from_point4(t_point4 *point);
t_vec4	vect4_from_point4(t_point4 a, t_point4 b);
void	*free_point4(t_point4 *point);
#endif

