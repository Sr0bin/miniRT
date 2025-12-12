/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:26:57 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 11:22:39 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "color.h"
#include <stdint.h>

t_color	color_add(t_color a, t_color b)
{
	t_color	temp;

	temp = (t_color){0};
	if (a.rgba.red + b.rgba.red <= UINT8_MAX)
		temp.rgba.red = a.rgba.red + b.rgba.red;
	else
		temp.rgba.red = UINT8_MAX;
	if (a.rgba.green + b.rgba.green <= UINT8_MAX)
		temp.rgba.green = a.rgba.green + b.rgba.green;
	else
		temp.rgba.green = UINT8_MAX;
	if (a.rgba.blue + b.rgba.blue <= UINT8_MAX)
		temp.rgba.blue = a.rgba.blue + b.rgba.blue;
	else
		temp.rgba.blue = UINT8_MAX;
	return (temp);
}

static uint8_t	add_color_component(uint8_t	first, uint8_t second, double coeff)
{
	if (((first * second) / UINT8_MAX) * coeff >= UINT8_MAX)
		return (UINT8_MAX);
	return (((uint8_t)(((first * second) / UINT8_MAX) * coeff)));
}

t_color	multiply_color_coeff(t_color first, t_color second, double coeff)
{
	t_color	temp;
	t_rgba	temp_rgba;
	t_rgba	first_rgba;
	t_rgba	second_rgba;

	temp = (t_color){0};
	first_rgba = first.rgba;
	second_rgba = second.rgba;
	temp_rgba.red = add_color_component(first_rgba.red, second_rgba.red, coeff);
	temp_rgba.green = add_color_component(first_rgba.green, second_rgba.green,
			coeff);
	temp_rgba.blue = add_color_component(first_rgba.blue, second_rgba.blue,
			coeff);
	temp.rgba = temp_rgba;
	return (temp);
}

t_color	dim_color(t_color color, double coeff)
{
	t_color	temp;

	if (color.rgba.red * coeff > UINT8_MAX)
		temp.rgba.red = UINT8_MAX;
	else
		temp.rgba.red = (uint8_t)(color.rgba.red * coeff);
	if (color.rgba.green * coeff > UINT8_MAX)
		temp.rgba.green = UINT8_MAX;
	else
		temp.rgba.green = (uint8_t)(color.rgba.green * coeff);
	if (color.rgba.blue * coeff > UINT8_MAX)
		temp.rgba.blue = UINT8_MAX;
	else
		temp.rgba.blue = (uint8_t)(color.rgba.blue * coeff);
	return (temp);
}
