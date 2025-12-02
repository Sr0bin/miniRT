/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:06:18 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 18:30:37 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "minirt.h"
#include <math.h>

int	is_normed(t_vec3 vec);

/* this function should:
 * return TRUE if a vec3/point is normalized
 * return FALSE if it it not normalized
*/
int	is_normed(t_vec3 vec)
{
	if (fabs(vec3_norm(vec)) - 1 > 1e-5)
		return (FALSE);
	else
		return (TRUE);
}
