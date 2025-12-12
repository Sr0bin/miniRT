/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:11:32 by jweber            #+#    #+#             */
/*   Updated: 2025/12/12 11:25:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "render.h"

void	free_rays(t_ray **ptr_array_rays)
{
	free(*ptr_array_rays);
	*ptr_array_rays = NULL;
	return ;
}
