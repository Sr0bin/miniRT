/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_opti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:41:35 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/16 15:41:51 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "object.h"

void	optimize_tangible(t_scene *p_scene)
{
	obj_iter(&p_scene->objects, p_scene, obj_update_amb);
}
