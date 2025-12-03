/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:11:32 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 19:09:22 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "render.h"

void	free_rays(t_ray **ptr_array_rays, size_t nb_rays)
{
	(void) nb_rays;
	// size_t	i;
	//
	// i = 0;
	// while (i < nb_rays)
	// {
	// 	if ((*ptr_array_rays)[i].direction != NULL)
	// 	{
	// 		free((*ptr_array_rays)[i].direction);
	// 		(*ptr_array_rays)[i].direction = NULL;
	// 	}
	// 	i++;
	// }
	free(*ptr_array_rays);
	*ptr_array_rays = NULL;
	return ;
}
