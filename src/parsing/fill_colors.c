/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:29:01 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 14:06:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "minirt.h"
#include "parsing.h"
#include "ft_string.h"

int			fill_colors(t_rgba *ptr_rgba, const char *str,
				char **ptr_str_err_msg);
static int	colors_wrong_nb_args(char **ptr_str_err_msg, const char *color_str);
static int	fill_from_splitted_colors(t_rgba *ptr_rgba,
				char **splitted_colors, char **ptr_str_err_msg);
int			get_color_i(char **splitted_colors, int color_i,
				uint8_t *ptr_color, char **ptr_str_err_msg);

/* to check 
 *	check_consecutive_comma fail : DONE -> OK !
 *	ft_split split fail : DONE -> OK !
 *	colors_wron_nb_ars fail : DONE -> OK !
 *	fill_from_splitted_fail : DONE -> OK !
 *	
*/

int	fill_colors(t_rgba *ptr_rgba,
		const char *colors_str, char **ptr_str_err_msg)
{
	char	**splitted_colors;
	int		ret;
	int		consecutive_comma;

	consecutive_comma = check_consecutive_comma(colors_str);
	if (consecutive_comma == TRUE)
		return (colors_wrong_nb_args(ptr_str_err_msg, colors_str));
	splitted_colors = ft_split(colors_str, ",");
	if (splitted_colors == NULL)
		return (FAILURE_MALLOC);
	if (splitted_colors[0] == NULL || splitted_colors [1] == NULL
		|| splitted_colors [2] == NULL || splitted_colors[3] != NULL)
	{
		ft_split_free(splitted_colors);
		return (colors_wrong_nb_args(ptr_str_err_msg, colors_str));
	}
	ret = fill_from_splitted_colors(ptr_rgba, splitted_colors, ptr_str_err_msg);
	ft_split_free(splitted_colors);
	return (ret);
}

/* to check :
 *	first get_color_i fail :  DONE -> OK;
 *	second get_color_i fail :  DONE -> OK;
 *	third get_color_i fail :  DONE -> OK;
*/

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

/* to check
 *	ft_atoi_safe fail : DONE -> OK !
 *	init_msg_atoi_failed fail : DONE -> OK !
 *	init_msg_wrong_color_value fail : DONE -> OK !
*/

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

/*	first ft_strjoin_free_first fail : DONE -> OK !
 *	second ft_strjoin_free_first fail : DONE -> OK !
 *	third ft_strjoin_free_first fail : DONE -> OK !
 *	fourth ft_strjoin_free_first fail : DONE -> OK !
*/

static int	colors_wrong_nb_args(char **ptr_str_err_msg, const char *color_str)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, color_str);
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
