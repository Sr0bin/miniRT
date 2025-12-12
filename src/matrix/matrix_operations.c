/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:07:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 11:46:14 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <math.h>

/*
* add_matrix: Create a new matrix, the result of addition matrix A + B.
* Matrices needs to be of the same size.
* Returns NULL in case of memory error during allocation.
*/

t_matrix	*add_matrix(t_matrix_const *a, t_matrix_const *b)
{
	size_t		i;
	size_t		j;
	t_matrix	*added;

	i = 0;
	if (a == NULL || b == NULL)
		return (NULL);
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

/*
* substract_matrix: Create a new matrix, the result of substraction matrix A - B.
* Matrices needs to be of the same size.
* Returns NULL in case of memory error during allocation.
*/

t_matrix	*substract_matrix(t_matrix_const *a, t_matrix_const *b)
{
	size_t		i;
	size_t		j;
	t_matrix	*substracted;

	i = 0;
	if (a == NULL || b == NULL)
		return (NULL);
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

static double	clc_sum(t_matrix_const *a, t_matrix_const *b, size_t i,
					size_t j)
{
	size_t	k;
	double	sum;

	if (a == NULL || b == NULL)
		return (nan(""));
	sum = 0;
	k = 0;
	while (k < a->col_size)
	{
		sum += a->index[i][k] * b->index[k][j];
		k++;
	}
	return (sum);
}

/*
* multiply_matrix: Create a new matrix, the result of multiplication 
* matrix A * B.
* Matrices needs to be of compatible sizes.
* Returns NULL in case of memory error during allocation.
*/

t_matrix	*multiply_matrix(t_matrix_const *a, t_matrix_const *b)
{
	size_t		i;
	size_t		j;
	t_matrix	*mult;

	i = 0;
	if (a == NULL || b == NULL)
		return (NULL);
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

/*
* scalar_matrix: Change the current matrix, the result of multiplication
* scalar * A.
* Returns NULL in case of error.
*/

void	scalar_matrix(t_matrix *matrix, double scalar)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (matrix == NULL)
		return ;
	while (i < matrix->row_size)
	{
		j = 0;
		while (j < matrix->col_size)
		{
			matrix->index[i][j] = matrix->index[i][j] * scalar;
			j++;
		}
		i++;
	}
}
