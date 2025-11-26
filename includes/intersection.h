/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:03:31 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/26 15:54:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H
# include "minirt.h"
# include "ray.h"
double	discriminant(double a, double b, double c);
double	intersection_sphere(t_ray ray, t_sphere sphere, t_point *intersection);
#endif

