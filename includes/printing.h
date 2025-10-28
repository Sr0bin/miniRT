/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:29:25 by jweber            #+#    #+#             */
/*   Updated: 2025/10/28 12:56:45 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H
# include "ray.h"
# define DELIMITOR "#########################\n"

int	print_error(int error);
void	print_delimitor(void);
void	print_color(t_color color);
void	print_ray(t_ray ray);
void	print_vector(t_vec3 *vector);

#endif
