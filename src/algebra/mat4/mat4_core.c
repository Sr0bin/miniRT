/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:42:59 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 12:42:34 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mat4.h"
#include "ft_standard.h"
#include "ft_memory.h"

/*
 * create_mat4: Creates a row*col size mat4, returns NULL in case of 
 * memory error.
*/

t_mat4	*mat4_alloc(void)
{
	t_mat4	*mat4;

	mat4 = ft_calloc(1, sizeof(t_mat4));
	if (mat4 == NULL)
		return (NULL);
	return (mat4);
}

/*
* mat4_copy: Creates a copy of an existing const mat4. Returns NULL on failed
* memory allocation.
*/
t_mat4	*mat4_duplicate(t_mat4_const mat4)
{
	t_mat4	*copy;

	copy = mat4_alloc();
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy->index, mat4.index, sizeof(mat4.index));
	return (copy);
}

/*
* free_mat4: Frees the mat4 and it's elements.
*/

void	*free_mat4(t_mat4 *mat4)
{
	free(mat4);
	return (NULL);
}

/*
* mat4_get_coord: Returns the number contained in the row*col.
*/

double	mat4_get_coord(const t_mat4 mat4, size_t row, size_t col)
{
	if (row > MAT4_SIZE || col > MAT4_SIZE)
		return (nan(""));
	return (mat4.index[row][col]);
}

/*
* mat4_set_coord: Sets the coord in row*col. 
*/

void	mat4_set_value(t_mat4 *mat4, size_t row, size_t col, double value)
{
	if (row > MAT4_SIZE || col > MAT4_SIZE)
		return ;
	mat4->index[row][col] = value;
}
