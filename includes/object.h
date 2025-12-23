/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:21 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/16 15:41:00 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "minirt.h"

t_object	*n_object(t_vector *ptr_objects, size_t n);
t_object	*iter_object(t_vector *ptr_objects, int (f)(t_object *));
t_object	*search_object(t_vector *ptr_objects, t_obj_type type, size_t n);
t_object	*search_object_group(t_vector *ptr_objects,
				t_obj_type type, size_t n);
t_color		*object_color(t_object	*ptr_obj);
t_color		object_ambient_color(t_object *obj, t_scene scene);
void		obj_update_amb(t_object *ptr_obj, void *ptr_scene);
void		obj_iter(t_vector *p_vec, void *ptr, void (*f)(t_object *, void *));
void		optimize_tangible(t_scene *p_scene);
int			scene_init(t_scene *scene, t_vector *ptr_objects);
int			free_scene(t_scene *scene);

#endif
