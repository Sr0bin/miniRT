/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_double3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:05:00 by jweber            #+#    #+#             */
/*   Updated: 2025/12/01 11:05:19 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	rotate_double3(double arr[3], double r[3][3])
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_x = r[0][0] * arr[X]
		+ r[0][1] * arr[Y]
		+ r[0][2] * arr[Z];
	tmp_y = r[1][0] * arr[X]
		+ r[1][1] * arr[Y]
		+ r[1][2] * arr[Z];
	tmp_z = r[2][0] * arr[X]
		+ r[2][1] * arr[Y]
		+ r[2][2] * arr[Z];
	arr[X] = tmp_x;
	arr[Y] = tmp_y;
	arr[Z] = tmp_z;
	return ;
}
