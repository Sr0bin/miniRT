/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:43:09 by jweber            #+#    #+#             */
/*   Updated: 2025/10/27 18:53:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ft_vectors.h"
# include "minirt.h"

# define WHITE_SPACE " \f\n\r\t\v"

int		parsing(int argc, char **argv, t_vector *ptr_objects);
int		check_args(int argc, char **argv);
int		get_file_content(char *filename, t_vector *ptr_file_content);
int		fill_obj_content(t_object *ptr_obj_tmp, char **elements);
int		fill_obj_ambient(t_object *ptr_obj_tmp, char **elements);
int		fill_obj_camera(t_object *ptr_obj_tmp, char **elements);
int		fill_obj_light(t_object *ptr_obj_tmp, char **elements);
int		fill_obj_sphere(t_object *ptr_obj_tmp, char **elements);
int		fill_obj_plane(t_object *ptr_obj_tmp, char **elements);
int		fill_obj_cylinder(t_object *ptr_obj_tmp, char **elements);
int		fill_colors(t_rgba *ptr_rgba, const char *str);
int		fill_coordinates(t_point **ptr_to_ptr_coo, const char *coo);
int		fill_direction(t_vec3 **ptr_to_ptr_direction, const char *direction,
			double min, double max);
int		fill_single_double_range(double *ptr_double, const char *str,
			double min, double max);
int		fill_single_double(double *ptr_double, const char *str);
void	free_obj_vector(t_vector **ptr_to_ptr_vec);

#endif // !PARSING_H
