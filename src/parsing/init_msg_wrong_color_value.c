/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msg_wrong_color_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:53:11 by jweber            #+#    #+#             */
/*   Updated: 2025/12/16 16:55:22 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ft_string.h"
#include "parsing.h"

/* to check
 *	first ft_strjoin_free_first fail : DONE -> OK !
 *	second ft_strjoin_free_first fail : DONE -> OK !
 *	third ft_strjoin_free_first fail : DONE -> OK !
*/

int	init_msg_wrong_color_value(char **splitted_colors, int color_i,
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
