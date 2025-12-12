/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:09:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 11:41:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/*
* matrix_set_identity: Set the matrix to it's identity. Matrix needs to be 
* square
* Example for a 4*4 : 
* |1 0 0 0|
* |0 1 0 0|
* |0 0 1 0|
* |0 0 0 1|
*/

void	*matrix_set_identity(t_matrix *matrix)
{
	size_t	i;

	i = 0;
	if (matrix == NULL)
		return (NULL);
	if (matrix->col_size != matrix->row_size)
		return (NULL);
	while (i < matrix->col_size)
	{
		matrix_set_value(matrix, i, i, 1);
		i++;
	}
	return (matrix);
}
