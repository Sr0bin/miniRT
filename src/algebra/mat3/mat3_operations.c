/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:28:00 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 11:31:10 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat3.h"

/*
* add_mat3: Create a new mat3, the result of addition mat3 A + B.
* Matrices needs to be of the same size.
*/

t_mat3	add_mat3(t_mat3_const a, t_mat3_const b)
{
	size_t		i;
	size_t		j;
	t_mat3		added;

	i = 0;
	while (i < MAT3_SIZE)
	{
		j = 0;
		while (j < MAT3_SIZE)
		{
			added.index[i][j] = a.index[i][j] + b .index[i][j];
			j++;
		}
		i++;
	}
	return (added);
}

/*
* substract_mat3: Create a new mat3, the result of substraction mat3 A - B.
*/

t_mat3	substract_mat3(t_mat3_const a, t_mat3_const b)
{
	size_t		i;
	size_t		j;
	t_mat3		substracted;

	i = 0;
	while (i < MAT3_SIZE)
	{
		j = 0;
		while (j < MAT3_SIZE)
		{
			substracted.index[i][j] = a.index[i][j] - b .index[i][j];
			j++;
		}
		i++;
	}
	return (substracted);
}

static double	clc_sum(t_mat3_const a, t_mat3_const b, size_t i, size_t j)
{
	size_t	k;
	double	sum;

	sum = 0;
	k = 0;
	while (k < MAT3_SIZE)
	{
		sum += a.index[i][k] * b.index[k][j];
		k++;
	}
	return (sum);
}

/*
* multiply_mat3: Create a new mat3, the result of multiplication mat3 A * B.
* Matrices needs to be of compatible sizes.
*/

t_mat3	multiply_mat3(t_mat3_const a, t_mat3_const b)
{
	size_t		i;
	size_t		j;
	t_mat3		mult;

	i = 0;
	while (i < MAT3_SIZE)
	{
		j = 0;
		while (j < MAT3_SIZE)
		{
			mult.index[i][j] = clc_sum(a, b, i, j);
			j++;
		}
		i++;
	}
	return (mult);
}

/*
* scalar_mat3: Change the current mat3, the result of multiplication scalar * A.
*/

t_mat3	scalar_mat3(t_mat3_const mat3, double scalar)
{
	size_t		i;
	size_t		j;
	t_mat3		new;

	i = 0;
	while (i < MAT3_SIZE)
	{
		j = 0;
		while (j < MAT3_SIZE)
		{
			new.index[i][j] = scalar * mat3.index[i][j];
			j++;
		}
		i++;
	}
	return (new);
}
