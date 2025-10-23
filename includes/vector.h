/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:25:18 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 18:23:38 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "matrix.h"

typedef struct s_matrix	t_vector3;
typedef struct s_matrix	t_point3;

t_vector3	*create_vector(double x, double y, double z);
double	vector_get_coord(t_vector3 vector, size_t i);
void	*free_vector(t_vector3 *vector);
double	dot_product(t_vector3 a, t_vector3 b);
t_vector3	*cross_product(t_vector3 a, t_vector3 b);
double	vector_norm(t_vector3 a);
void	print_vector(t_vector3 *vector);
#endif
