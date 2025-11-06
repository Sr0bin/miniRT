/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:36:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/06 18:12:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
# include "matrix.h"
# include "vector.h"

typedef struct s_matrix	t_point;

t_point	*create_point(double x, double y, double z);
double	point_get_coord(t_point point, size_t i);
t_point	*offset_point(t_point *point, t_vec3 *vector);
t_vec3	*vector_from_point(t_point *point);
t_vec3	*vector_points(t_point *a, t_point *b);
void	*free_point(t_point *point);
double	points_distance(t_point *a, t_point *b);
#endif
