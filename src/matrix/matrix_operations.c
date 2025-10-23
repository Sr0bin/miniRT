/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:07:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/10/23 15:27:09 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*add_matrix(t_matrix_const *a, t_matrix_const *b)
{
	size_t		i;
	size_t		j;
	t_matrix	*added;

	i = 0;
	if (a->row_size != b->row_size || a->col_size != b->col_size)
		return (NULL);
	added = create_matrix(a->row_size, a->col_size);
	if (added == NULL)
		return (NULL);
	while (i < a->row_size)
	{
		j = 0;
		while (j < a->col_size)
		{
			added->index[i][j] = a->index[i][j] + b ->index[i][j];
			j++;
		}
		i++;
	}
	return (added);
}

t_matrix	*substract_matrix(t_matrix_const *a, t_matrix_const *b)
{
	size_t		i;
	size_t		j;
	t_matrix	*substracted;

	i = 0;
	if (a->row_size != b->row_size || a->col_size != b->col_size)
		return (NULL);
	substracted = create_matrix(a->row_size, a->col_size);
	if (substracted == NULL)
		return (NULL);
	while (i < a->row_size)
	{
		j = 0;
		while (j < a->col_size)
		{
			substracted->index[i][j] = a->index[i][j] - b ->index[i][j];
			j++;
		}
		i++;
	}
	return (substracted);
}

//TODO: Add NULL CHECK
static float	clc_sum(t_matrix_const *a, t_matrix_const *b, size_t i, size_t j)
{
	size_t	k;
	float	sum;

	sum = 0;
	k = 0;
	while (k < a->col_size)
	{
		sum += a->index[i][k] * b->index[k][j];
		k++;
	}
	return (sum);
}

t_matrix	*multiply_matrix(t_matrix_const *a, t_matrix_const *b)
{
	size_t		i;
	size_t		j;
	t_matrix	*mult;

	i = 0;
	if (a->col_size != b->row_size)
		return (NULL);
	mult = create_matrix(a->row_size, b->col_size);
	if (mult == NULL)
		return (NULL);
	while (i < a->row_size)
	{
		j = 0;
		while (j < b->col_size)
		{
			mult->index[i][j] = clc_sum(a, b, i, j);
			j++;
		}
		i++;
	}
	return (mult);
}

t_matrix	*scalar_matrix(t_matrix_const *matrix, float scalar)
{
	size_t		i;
	size_t		j;
	t_matrix	*scaled;

	i = 0;
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
