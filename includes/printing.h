/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:33 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 16:47:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H
# include "ray.h"
# define DELIMITOR "#########################\n"

# include "ft_vectors.h"

int		print_error(int error, char *str);
int		print_objects(t_vector objects);
void	print_delimitor(void);
void	print_color(t_color color);
void	print_ray(t_ray ray);
void	print_vector(t_vec3 *vector);

#endif
