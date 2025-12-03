/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:05:47 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 14:13:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stddef.h>
# include <stdio.h>
# include <math.h>

/*
	* Simple lib for matrix representation. It is represented as a double array of float.
	* Each matrix is allocatedm and a new one is created when you do an operation.
	* That ensures that no data is lost, and care must be taken to free everything in the
	* end.
	* Each operation on the matrices need to be done on the lib to ensure that
	* no date corruption can occur, with no out of bound comportement.
	* TODO : Check that errors are properly managed.
*/

typedef struct s_matrix
{
	double	**index;
	size_t	row_size;
	size_t	col_size;
}	t_matrix;

typedef const t_matrix	t_matrix_const;

t_matrix	*create_matrix(size_t row, size_t col);
void		*free_matrix(t_matrix *matrix);
t_matrix	*matrix_duplicate(t_matrix_const *matrix);
double		matrix_get_coord(t_matrix *matrix, size_t row, size_t col);
void		matrix_set_value(t_matrix *mat, size_t row, size_t col, double value);
void		*matrix_set_identity(t_matrix *matrix);
t_matrix	*substract_matrix(t_matrix_const *a, t_matrix_const *b);
t_matrix	*add_matrix(t_matrix_const *a, t_matrix_const *b);
t_matrix	*scalar_matrix_new(t_matrix_const *matrix, double scalar);
void		scalar_matrix(t_matrix *matrix, double scalar);
t_matrix	*multiply_matrix(t_matrix_const *a, t_matrix_const *b);

void	print_matrix(t_matrix_const *matrix);
#endif
