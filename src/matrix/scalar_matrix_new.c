/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_matrix_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:43:18 by jweber            #+#    #+#             */
/*   Updated: 2025/12/12 11:43:26 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*scalar_matrix_new(t_matrix_const *matrix, double scalar)
{
	size_t		i;
	size_t		j;
	t_matrix	*scaled;

	i = 0;
	if (matrix == NULL)
		return (NULL);
	scaled = create_matrix(matrix->row_size, matrix->col_size);
	if (scaled == NULL)
		return (NULL);
	while (i < matrix->row_size)
	{
		j = 0;
		while (j < matrix->col_size)
		{
			scaled->index[i][j] = matrix->index[i][j] * scalar;
			j++;
		}
		i++;
	}
	return (scaled);
}
