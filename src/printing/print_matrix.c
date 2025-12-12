/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 11:44:15 by jweber            #+#    #+#             */
/*   Updated: 2025/12/12 11:44:51 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"
#include "matrix.h"

void	print_matrix(t_matrix_const *matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < matrix->row_size || i == 0)
	{
		j = 0;
		while (j < matrix->col_size || j == 0)
		{
			printf("%f ", matrix->index[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
