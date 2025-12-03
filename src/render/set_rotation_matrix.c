/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:41:49 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 18:28:29 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	set_rotation_matrix_x(t_mat3 *rotation_matrix, double theta);
static void	set_rotation_matrix_y(t_mat3 *rotation_matrix, double theta);
static void	set_rotation_matrix_z(t_mat3 *rotation_matrix, double theta);

/* This function set value in rotation_matrix accordingly to the angle and
 * the axis about which we need to rotate
*/
void	set_rotation_matrix(t_mat3 *rotation_matrix, double theta, int axis)
{
	if (axis == X)
	{
		set_rotation_matrix_x(rotation_matrix, theta);
		return ;
	}
	if (axis == Y)
	{
		set_rotation_matrix_y(rotation_matrix, theta);
		return ;
	}
	if (axis == Z)
	{
		set_rotation_matrix_z(rotation_matrix, theta);
		return ;
	}
	return ;
}

static void	set_rotation_matrix_x(t_mat3 *rotation_matrix, double theta)
{
	rotation_matrix->index[0][0] = 1;
	rotation_matrix->index[0][1] = 0;
	rotation_matrix->index[0][2] = 0;
	rotation_matrix->index[1][0] = 0;
	rotation_matrix->index[1][1] = cos(theta);
	rotation_matrix->index[1][2] = -sin(theta);
	rotation_matrix->index[2][0] = 0;
	rotation_matrix->index[2][1] = sin(theta);
	rotation_matrix->index[2][2] = cos(theta);

}

static void	set_rotation_matrix_y(t_mat3 *rotation_matrix, double theta)
{
	rotation_matrix->index[0][0] = cos(theta);
	rotation_matrix->index[0][1] = 0;
	rotation_matrix->index[0][2] = sin(theta);
	rotation_matrix->index[1][0] = 0;
	rotation_matrix->index[1][1] = 1;
	rotation_matrix->index[1][2] = 0;
	rotation_matrix->index[2][0] = -sin(theta);
	rotation_matrix->index[2][1] = 0;
	rotation_matrix->index[2][2] = cos(theta);
}

static void	set_rotation_matrix_z(t_mat3 *rotation_matrix, double theta)
{
	rotation_matrix->index[0][0] = cos(theta);
	rotation_matrix->index[0][1] = -sin(theta);
	rotation_matrix->index[0][2] = 0;
	rotation_matrix->index[1][0] = sin(theta);
	rotation_matrix->index[1][1] = cos(theta);
	rotation_matrix->index[1][2] = 0;
	rotation_matrix->index[2][0] = 0;
	rotation_matrix->index[2][1] = 0;
	rotation_matrix->index[2][2] = 1;
}
