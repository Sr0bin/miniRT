/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_obj_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:38:06 by jweber            #+#    #+#             */
/*   Updated: 2025/12/03 15:25:22 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "point3.h"
#include "vec3.h"

void	free_obj_vector(t_vector *ptr_vec);

void	free_obj_vector(t_vector *ptr_vec)
{
	free(ptr_vec->data);
	ptr_vec->data = NULL;
	ptr_vec->data_size = 0;
	ptr_vec->size = 0;
	ptr_vec->capacity = 0;
}
