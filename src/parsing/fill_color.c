/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:08:35 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "minirt.h"

int			fill_colors(t_rgba *ptr_rgba, const char *str);
static int	fill_from_splitted_colors(t_rgba *ptr_rgba, char **splitted_colors);

int	fill_colors(t_rgba *ptr_rgba, const char *str)
{
	char	**splitted_colors;
	int		ret;

	splitted_colors = ft_split(str, ",");
	if (splitted_colors == NULL)
		return (FAILURE_MALLOC);
	ret = fill_from_splitted_colors(ptr_rgba, splitted_colors);
	ft_split_free(splitted_colors);
	return (ret);
}

static int	fill_from_splitted_colors(t_rgba *ptr_rgba, char **splitted_colors)
{
	int		tmp_colors;
	int		ret;

	if (splitted_colors[0] == NULL || splitted_colors [1] == NULL
		|| splitted_colors [2] == NULL || splitted_colors[3] != NULL)
		return (FAILURE_PARSE_COLOR_WRONG_FORMAT);
	ret = ft_atoi_safe(splitted_colors[0], &tmp_colors);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COLOR_ATOI_FAILED);
	if (tmp_colors < 0 || tmp_colors > 255)
		return (FAILURE_PARSE_COLOR_WRONG_VALUE);
	ptr_rgba->red = (uint8_t) tmp_colors;
	ret = ft_atoi_safe(splitted_colors[1], &tmp_colors);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COLOR_ATOI_FAILED);
	if (tmp_colors < 0 || tmp_colors > 255)
		return (FAILURE_PARSE_COLOR_WRONG_VALUE);
	ptr_rgba->green = (uint8_t) tmp_colors;
	ret = ft_atoi_safe(splitted_colors[2], &tmp_colors);
	if (ret != SUCCESS)
		return (FAILURE_PARSE_COLOR_ATOI_FAILED);
	if (tmp_colors < 0 || tmp_colors > 255)
		return (FAILURE_PARSE_COLOR_WRONG_VALUE);
	ptr_rgba->blue = (uint8_t) tmp_colors;
	return (SUCCESS);
}
