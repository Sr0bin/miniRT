/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:41:16 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/15 11:27:22 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT4_H
# define MAT4_H

# define MAT4_SIZE 4

# include <stddef.h>
# include <math.h>

typedef struct s_mat4
{
	double	index[4][4];
}	t_mat4;

typedef const t_mat4	t_mat4_const;

t_mat4		*mat4_alloc(void);
void		*free_mat4(t_mat4 *mat4);
t_mat4		*mat4_duplicate(t_mat4_const mat4);
double		mat4_get_coord(t_mat4 mat4, size_t row, size_t col);
void		mat4_set_value(t_mat4 *mat, size_t row, size_t col, double value);
void		*mat4_set_identity(t_mat4 *mat4);
t_mat4		substract_mat4(t_mat4_const a, t_mat4_const b);
t_mat4		add_mat4(t_mat4_const a, t_mat4_const b);
t_mat4		scalar_mat4(t_mat4_const mat4, double scalar);
t_mat4		multiply_mat4(t_mat4_const a, t_mat4_const b);

void		print_mat4(t_mat4_const *mat4);
#endif
