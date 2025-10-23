/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:09:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 15:24:57 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	*matrix_set_identity(t_matrix *matrix)
{
	size_t	i;

	i = 0;
	if (matrix->col_size != matrix->row_size)
		return (NULL);
	while (i < matrix->col_size)
	{
		matrix_set_coord(matrix, i, i, 1);
		i++;
	}
	return (matrix);
}
