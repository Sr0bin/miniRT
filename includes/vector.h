/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/28 14:40:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "matrix.h"

typedef struct s_matrix	t_vec3;

typedef enum e_axis
{
	X = 0,
	Y,
	Z,
	W
}	t_axis;

t_vec3	*create_vector(double x, double y, double z);
t_vec3	*vector_copy(t_vec3 vector);
double	vector_get_coord(t_vec3 vector, t_axis axis);
void	vector_set_value(t_vec3 *vector, t_axis axis, double value);
void	*free_vector(t_vec3 *vector);
void	scalar_vector(t_vec3 *vector, double scalar);
double	dot_product(t_vec3 a, t_vec3 b);
t_vec3	*cross_product(t_vec3 a, t_vec3 b);
double	vector_norm(t_vec3 a);
void	normalize_vector(t_vec3	*vector);
t_vec3	*reflection_vector(t_vec3 incident, t_vec3 normal);
#endif
