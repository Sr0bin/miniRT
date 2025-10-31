/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/10/31 12:47:29 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "minirt.h"
#include "parsing.h"
#include "ft_string.h"

int			fill_colors(t_rgba *ptr_rgba, const char *str,
				char **ptr_str_err_msg);
static int	fill_from_splitted_colors(t_rgba *ptr_rgba,
				char **splitted_colors, char **ptr_str_err_msg);

int	fill_colors(t_rgba *ptr_rgba, const char *str, char **ptr_str_err_msg)
{
	char	**splitted_colors;
	int		ret;

	splitted_colors = ft_split(str, ",");
	if (splitted_colors == NULL)
		return (FAILURE_MALLOC);
	if (splitted_colors[0] == NULL || splitted_colors [1] == NULL
		|| splitted_colors [2] == NULL || splitted_colors[3] != NULL)
	{
		ft_split_free(splitted_colors);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, str);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "': ");
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
				MSG_COLOR_WRONG_ARGUMENTS);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
		return (FAILURE_PARSE_PERSONNALIZED);
	}
	ret = fill_from_splitted_colors(ptr_rgba, splitted_colors, ptr_str_err_msg);
	ft_split_free(splitted_colors);
	return (ret);
}

int			get_color_i(char **splitted_colors, int color_i,
				uint8_t *ptr_color, char **ptr_str_err_msg);

static int	fill_from_splitted_colors(t_rgba *ptr_rgba,
				char **splitted_colors, char **ptr_str_err_msg)
{
	int		ret;

	ret = get_color_i(splitted_colors, 0, &ptr_rgba->red, ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	ret = get_color_i(splitted_colors, 1, &ptr_rgba->green, ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	ret = get_color_i(splitted_colors, 2, &ptr_rgba->blue, ptr_str_err_msg);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}

static int	init_msg_wrong_color_value(char **splitted_colors, int color_i,
				char **ptr_str_err_msg);

int	get_color_i(char **splitted_colors, int color_i,
		uint8_t *ptr_color, char **ptr_str_err_msg)
{
	int	tmp_color;
	int	ret;

	ret = ft_atoi_safe(splitted_colors[color_i], &tmp_color);
	if (ret != SUCCESS)
	{
		return (init_msg_atoi_failed(ptr_str_err_msg,
				ret, splitted_colors[color_i]));
	}
	if (tmp_color < 0 || tmp_color > 255)
	{
		return (init_msg_wrong_color_value(splitted_colors,
				color_i, ptr_str_err_msg));
	}
	*ptr_color = (uint8_t) tmp_color;
	return (SUCCESS);
}

static int	init_msg_wrong_color_value(char **splitted_colors, int color_i,
				char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			splitted_colors[color_i]);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"': color value must be between 0 and 255\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}
