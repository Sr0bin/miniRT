/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:00:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 11:29:40 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H
# include "minirt.h"

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

t_vec4	*vec4_alloc(double x, double y, double z, double w);
t_vec4	*vect4_copy(t_vec4 vector);
double	vec4_get(t_vec4 vector, t_axis axis);
void	vec4_set(t_vec4 *vector, t_axis axis, double value);
t_vec4	vec4_set_all(double x, double y, double z, double w);
void	*free_vec4(t_vec4 *vector);
t_vec4	vec4_scale(t_vec4 vector, double scalar);
double	dot_product4(t_vec4 a, t_vec4 b);
t_vec4	vec4_add(t_vec4 a, t_vec4 b);
t_vec4	vec4_subtract(t_vec4 a, t_vec4 b);
t_vec4	cross_product4(t_vec4 a, t_vec4 b);
double	vector_norm4(t_vec4 a);
void	normalize_vec4(t_vec4	*vector);
t_vec4	reflection_vector4(t_vec4 incident, t_vec4 normal);
#endif
