/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:45:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 11:43:08 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"

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

void	normalize_vec3(t_vec3	*vector)
{
	*vector = vec3_scale(*vector, 1 / vec3_norm(*vector));
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
	return (vec3_set_all(tmp_x, tmp_y, tmp_z));
}
