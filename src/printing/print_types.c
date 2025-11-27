/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:49:37 by rorollin          #+#    #+#             */
/*   Updated: 2025/11/27 18:58:11 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"
#include "ray.h"

void	print_delimitor(void)
{
	printf(DELIMITOR);
}
void	print_color(t_color color)
{
	print_delimitor();
	printf("Red : %d\nBlue : %d\nGreen : %d\nAlpha : %d\n",
		color.rgba.red,
		color.rgba.blue,
		color.rgba.green,
		color.rgba.alpha);
}

void	print_vector(t_vec3 *vector)
{
	(void) vector;
	print_delimitor();
	// print_matrix(vector);
}

void	print_ray(t_ray ray)
{
	print_delimitor();
	printf("Ray start :\n");
	// print_matrix(ray.origin);
	printf("Ray direction :\n");
	print_vector(ray.direction);
	printf("Ray color :\n");
	print_color(ray.color);
}
