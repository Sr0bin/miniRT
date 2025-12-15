/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:49:40 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 12:43:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

/*
* add_mat4: Create a new mat4, the result of addition mat4 A + B.
* Matrices needs to be of the same size.
* Returns NULL in case of memory error during allocation.
*/

t_mat4	add_mat4(t_mat4_const a, t_mat4_const b)
{
	size_t		i;
	size_t		j;
	t_mat4		added;

	i = 0;
	while (i < MAT4_SIZE)
	{
		j = 0;
		while (j < MAT4_SIZE)
		{
			added.index[i][j] = a.index[i][j] + b .index[i][j];
			j++;
		}
		i++;
	}
	return (added);
}

/*
* substract_mat4: Create a new mat4, the result of substraction mat4 A - B.
*/

t_mat4	substract_mat4(t_mat4_const a, t_mat4_const b)
{
	size_t		i;
	size_t		j;
	t_mat4		substracted;

	i = 0;
	while (i < MAT4_SIZE)
	{
		j = 0;
		while (j < MAT4_SIZE)
		{
			substracted.index[i][j] = a.index[i][j] - b .index[i][j];
			j++;
		}
		i++;
	}
	return (substracted);
}

static double	clc_sum(t_mat4_const a, t_mat4_const b, size_t i, size_t j)
{
	size_t	k;
	double	sum;

	sum = 0;
	k = 0;
	while (k < MAT4_SIZE)
	{
		sum += a.index[i][k] * b.index[k][j];
		k++;
	}
	return (sum);
}

/*
* multiply_mat4: Create a new mat4, the result of multiplication mat4 A * B.
* Matrices needs to be of compatible sizes.
* Returns NULL in case of memory error during allocation.
*/

t_mat4	multiply_mat4(t_mat4_const a, t_mat4_const b)
{
	size_t		i;
	size_t		j;
	t_mat4		mult;

	i = 0;
	while (i < MAT4_SIZE)
	{
		j = 0;
		while (j < MAT4_SIZE)
		{
			mult.index[i][j] = clc_sum(a, b, i, j);
			j++;
		}
		i++;
	}
	return (mult);
}

/*
* scalar_mat4: Change the current mat4, the result of multiplication scalar * A.
*/

t_mat4	scalar_mat4(t_mat4_const mat4, double scalar)
{
	size_t		i;
	size_t		j;
	t_mat4		new;

	i = 0;
	while (i < MAT4_SIZE)
	{
		j = 0;
		while (j < MAT4_SIZE)
		{
			new.index[i][j] = scalar * mat4.index[i][j];
			j++;
		}
		i++;
	}
	return (new);
}
