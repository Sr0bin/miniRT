/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:20:44 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/08 17:22:33 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "minirt.h"

t_color	multiply_color_coeff(t_color first, t_color second, double coeff);
t_color	dim_color(t_color color, double coeff);
t_color	color_add(t_color a, t_color b);
#endif

