/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:07:05 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/02 15:53:06 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT3_H
# define MAT3_H
# define MAT3_SIZE 3

# include <stddef.h>
# include <math.h>

typedef struct s_mat3
{
	double	index[3][3];
}	t_mat3;

typedef const t_mat3	t_mat3_const;

t_mat3		*mat3_alloc(void);
void		*free_mat3(t_mat3 *mat3);
t_mat3		*mat3_duplicate(t_mat3_const mat3);
double		mat3_get_coord(t_mat3 mat3, size_t row, size_t col);
void		mat3_set_value(t_mat3 *mat, size_t row, size_t col, double value);
void		*mat3_set_identity(t_mat3 *mat3);
t_mat3	substract_mat3(t_mat3_const a, t_mat3_const b);
t_mat3	add_mat3(t_mat3_const a, t_mat3_const b);
t_mat3		scalar_mat3(t_mat3_const mat3, double scalar);
t_mat3	multiply_mat3(t_mat3_const a, t_mat3_const b);

void	print_mat3(t_mat3_const *mat3);
#endif
