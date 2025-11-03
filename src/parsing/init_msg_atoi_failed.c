/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msg_atoi_failed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:15:56 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 16:16:24 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "minirt.h"

int			init_msg_atoi_failed(char **ptr_str_err_msg,
				int ret, char *input);
static int	msg_atoi_wrong_input(char **ptr_str_err_msg);
static int	msg_atoi_overflow_underflow(char **ptr_str_err_msg);
static int	msg_atoi_too_large_input(char **ptr_str_err_msg);

int	init_msg_atoi_failed(char **ptr_str_err_msg,
		int ret, char *input)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, input);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	if (ret == ATOI_SAFE_TOO_LARGE_INPUT)
	{
		return (msg_atoi_too_large_input(ptr_str_err_msg));
	}
	else if (ret == ATOI_SAFE_OVERFLOW || ret == ATOF_SAFE_UNDERFLOW)
	{
		return (msg_atoi_overflow_underflow(ptr_str_err_msg));
	}
	else if (ret == ATOI_SAFE_WRONG_INPUT)
	{
		return (msg_atoi_wrong_input(ptr_str_err_msg));
	}
	*ptr_str_err_msg = ft_strjoin_free_second("'", *ptr_str_err_msg);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	msg_atoi_too_large_input(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"...': given value can not be converted to int"
			"input string is too long to get converted\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	msg_atoi_overflow_underflow(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"': value can not be converted to int: "
			"will overflow / underflow\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	msg_atoi_wrong_input(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"': unexepected character while processing conversion\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}
