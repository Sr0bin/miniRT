/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:06:18 by jweber            #+#    #+#             */
/*   Updated: 2025/11/03 16:07:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "minirt.h"
#include <math.h>

int	is_normed(t_vec3 vec);

/* this function should:
 * return TRUE if a vec3/point is normalized
 * return FALSE if it it not normalized
*/
int	is_normed(t_vec3 vec)
{
	if (fabs(sqrt(vec.index[0][0] * vec.index[0][0]
		+ vec.index[1][0] * vec.index[1][0]
		+ vec.index[2][0] * vec.index[2][0])) - 1 > 1e-5)
		return (FALSE);
	else
		return (TRUE);
}
