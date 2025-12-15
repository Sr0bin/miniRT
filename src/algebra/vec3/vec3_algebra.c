/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_algebra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:42:14 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 11:44:14 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"

double	dot_product3(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	cross_product3(t_vec3 a, t_vec3 b)
{
	double	x;
	double	y;
	double	z;
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
