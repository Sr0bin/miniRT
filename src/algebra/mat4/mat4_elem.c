/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:49:01 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 11:31:45 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

void	*mat4_set_identity(t_mat4 *mat4)
{
	size_t	i;

	i = 0;
	if (mat4 == NULL)
		return (NULL);
	while (i < MAT4_SIZE)
	{
		mat4_set_value(mat4, i, i, 1);
		i++;
	}
	return (mat4);
}
