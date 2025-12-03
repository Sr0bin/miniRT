/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:21 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/26 15:06:36 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "minirt.h"

t_object	*n_object(t_vector *ptr_objects, size_t n);
t_object	*iter_object(t_vector *ptr_objects, int (f)(t_object *));
t_object	*search_object(t_vector *ptr_objects, t_obj_type type, size_t n);
t_object	*search_object_group(t_vector *ptr_objects, t_obj_type type, size_t n);
int	obj_fill_type_vec(t_vector *to_fill, t_vector *ptr_objects, t_obj_type type);
int	obj_fill_tangible_vec(t_vector *to_fill, t_vector *ptr_objects);
int		scene_init(t_scene *scene, t_vector *ptr_objects);
void	free_scene(t_scene *scene);


#endif

