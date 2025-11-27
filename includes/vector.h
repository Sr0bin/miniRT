/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/27 18:59:26 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# define AXIS_COUNT 4
# include "matrix.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef enum e_axis
{
	X = 0,
	Y,
	Z,
	W
}	t_axis;

t_vec3	*vec3_alloc(double x, double y, double z);
t_vec3	*vect3_copy(t_vec3 vector);
double	vec3_get(t_vec3 vector, t_axis axis);
void	vec3_set(t_vec3 *vector, t_axis axis, double value);
t_vec3	vec3_set_all(double x, double y, double z);
void	*free_vector(t_vec3 *vector);
t_vec3	vec3_scale(t_vec3 vector, double scalar);
double	dot_product(t_vec3 a, t_vec3 b);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_subtract(t_vec3 a, t_vec3 b);
t_vec3	cross_product(t_vec3 a, t_vec3 b);
double	vector_norm(t_vec3 a);
void	normalize_vector(t_vec3	*vector);
t_vec3	reflection_vector(t_vec3 incident, t_vec3 normal);
#endif
