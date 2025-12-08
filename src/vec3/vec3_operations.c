/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:45:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/08 15:44:19 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"

double	dot_product3(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double	vec3_norm(t_vec3 a)
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

t_vec3	vec3_add(t_vec3 a, t_vec3 b)
{
	return (vec3_set_all(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3	vec3_subtract(t_vec3 a, t_vec3 b)
{
	return (vec3_set_all(a.x - b.x, a.y - b.y, a.z - b.z));
}
/*
* WARNING : Normal needs to be normalized
*/

t_vec3	reflection_vector3(t_vec3 incident, t_vec3 normal)
{
	double	dot;
	t_vec3	temp;
	t_vec3	result;

	temp = normal;
	dot = dot_product3(incident, normal);
	temp = vec3_scale(temp, (-2 * dot));
	result = vec3_add(incident, temp);
	return (result);
}

void	normalize_vec3(t_vec3	*vector)
{
	*vector = vec3_scale(*vector, 1 / vec3_norm(*vector));
}

t_vec3	cross_product3(t_vec3 a, t_vec3 b)
{
	double x;
	double y;
	double z;
	t_vec3	vector;

	x = (vec3_get(a, Y) * vec3_get(b, Z))
		- (vec3_get(a, Z) * vec3_get(b, Y));
	y = (vec3_get(a, Z) * vec3_get(b, X))
		- (vec3_get(a, X) * vec3_get(b, Z));
	z = (vec3_get(a, X) * vec3_get(b, Y))
		- (vec3_get(a, Y) * vec3_get(b, X));
	vector = vec3_set_all(x, y, z);
	return (vector);
}

t_vec3	vec3_mult_mat3(t_vec3 vec, t_mat3 mat)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = (mat.index[X][X] * vec.x)
		+ (mat.index[X][Y] * vec.y)
		+ (mat.index[X][Z] * vec.z);
	tmp_y = (mat.index[Y][X] * vec.x)
		+ (mat.index[Y][Y] * vec.y)
		+ (mat.index[Y][Z] * vec.z);
	tmp_z = (mat.index[Z][X] * vec.x)
		+ (mat.index[Z][Y] * vec.y)
		+ (mat.index[Z][Z] * vec.z);
	return(vec3_set_all(tmp_x, tmp_y, tmp_z));
}
