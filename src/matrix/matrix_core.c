/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:07:11 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 15:09:24 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	create_matrix(size_t row, size_t col)
{
	t_matrix	matrix;
	size_t		i;

	matrix = ft_calloc(1, sizeof(t_matrix_struct));
	i = 0;
	if (matrix == NULL)
		return (NULL);
	matrix->col_size = col;
	matrix->row_size = row;
	matrix->index = (float **) ft_calloc(row + 1, sizeof(float *));
	if (matrix->index == NULL)
	{
		free(matrix);
		return (NULL);
	}
	while (i < row)
	{
		(matrix->index)[i] = ft_calloc(col + 1, sizeof(float));
		if ((matrix->index)[i] == NULL)
			return (free_matrix(matrix));
		i++;
	}
	return (matrix);
}

t_matrix	matrix_copy(t_matrix_const matrix)
{
	size_t		i;
	size_t		j;
	t_matrix	copy;

	i = 0;
	copy = create_matrix(matrix->row_size, matrix->col_size);
	if (copy == NULL)
		return (NULL);
	while (i < matrix->row_size)
	{
		j = 0;
		while (j < matrix->col_size)
		{
			copy->index[i][j] = matrix->index[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

void	*free_matrix(t_matrix matrix)
{
	size_t	i;

	i = 0;
	if (matrix == NULL)
		return (NULL);
	while (i <= matrix->row_size)
		free(matrix->index[i++]);
	free((void *) matrix->index);
	free(matrix);
	return (NULL);
}

float	matrix_get_coord(t_matrix matrix, size_t row, size_t col)
{
	if (row > matrix->row_size || col > matrix->col_size)
		return (NAN);
	return (matrix->index[row][col]);
}

void	matrix_set_coord(t_matrix matrix, size_t row, size_t col, float value)
{
	matrix->index[row][col] = value;
}
