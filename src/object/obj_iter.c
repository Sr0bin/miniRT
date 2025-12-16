/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:13:45 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/16 15:32:32 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "object.h"
#include "printing.h"

void	obj_iter(t_vector *p_vec, void *ptr, void (*f)(t_object *, void *))
{
	size_t		i;
	t_object	*p_crnt_obj;

	i = 0;
	while (i < p_vec->size)
	{
		p_crnt_obj = (t_object *)(((char *)p_vec->data) + p_vec->data_size * i);
		f(p_crnt_obj, ptr);
		i++;
	}
}
