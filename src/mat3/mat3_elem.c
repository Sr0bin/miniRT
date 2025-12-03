/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:22:26 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 14:34:42 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat3.h"

void	*mat3_set_identity(t_mat3 *mat3)
{
	size_t	i;

	i = 0;
	if (mat3 == NULL)
		return (NULL);
	while (i < MAT3_SIZE)
	{
		mat3_set_value(mat3, i, i, 1);
		i++;
	}
	return (mat3);
}
