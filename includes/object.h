/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:21 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/04 13:37:48 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "minirt.h"

t_object	*n_object(t_vector *ptr_objects, size_t n);
t_object	*iter_object(t_vector *ptr_objects, int (f)(t_object *));
t_object	*search_object(t_vector *ptr_objects, t_obj_type type, size_t n);
t_object	*search_object_group(t_vector *ptr_objects, t_obj_type type, size_t n);
int			scene_init(t_scene *scene, t_vector *ptr_objects);
void		free_scene(t_scene *scene);


#endif

