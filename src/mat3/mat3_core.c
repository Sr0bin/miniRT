/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:07:09 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 15:45:33 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mat3.h"
#include "ft_standard.h"
#include "ft_memory.h"

/*
 * create_mat3: Creates a row*col size mat3, returns NULL in case of 
 * memory error.
*/

t_mat3	*mat3_alloc(void)
{
	t_mat3	*mat3;

	mat3 = ft_calloc(1, sizeof(t_mat3));
	if (mat3 == NULL)
		return (NULL);
	return (mat3);
}

/*
* mat3_copy: Creates a copy of an existing const mat3. Returns NULL on failed
* memory allocation.
*/
t_mat3	*mat3_duplicate(t_mat3_const mat3)
{
	t_mat3	*copy;

	copy = mat3_alloc();
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy->index, mat3.index, sizeof(mat3.index));
	return (copy);
}

/*
* free_mat3: Frees the mat3 and it's elements.
*/

void	*free_mat3(t_mat3 *mat3)
{
	free(mat3);
	return (NULL);
}

/*
* mat3_get_coord: Returns the number contained in the row*col.
*/

double	mat3_get_coord(const t_mat3 mat3, size_t row, size_t col)
{
	if (row > MAT3_SIZE || col > MAT3_SIZE)
		return (nan(""));
	return (mat3.index[row][col]);
}

/*
* mat3_set_coord: Sets the coord in row*col. 
*/

void	mat3_set_value(t_mat3 *mat3, size_t row, size_t col, double value)
{
	//TODO: check if row col is out of bounds
	if (row > MAT3_SIZE || col > MAT3_SIZE)
		return ; 
	mat3->index[row][col] = value;
}

void	print_mat3(t_mat3_const *mat3)
{
	size_t	i;
	size_t	j;
	i = 0;
	while (i < MAT3_SIZE || i == 0)
	{
		j = 0;
		while (j < MAT3_SIZE || j == 0)
		{
			printf("%f ",mat3->index[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
