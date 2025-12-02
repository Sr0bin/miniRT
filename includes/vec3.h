/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:59:06 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 18:30:37 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECT3_H
# define VECT3_H
# include "mat3.h"

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
void	*free_vec3(t_vec3 *vector);
t_vec3	vec3_scale(t_vec3 vector, double scalar);
double	dot_product3(t_vec3 a, t_vec3 b);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_subtract(t_vec3 a, t_vec3 b);
t_vec3	cross_product3(t_vec3 a, t_vec3 b);
double	vec3_norm(t_vec3 a);
void	normalize_vec3(t_vec3	*vector);
t_vec3	reflection_vector3(t_vec3 incident, t_vec3 normal);
t_vec3	vec3_mult_mat3(t_vec3 vec, t_mat3 mat);
#endif
