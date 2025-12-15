/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msg_atof_failed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:13:17 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 14:24:21 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "minirt.h"

int			init_msg_atof_failed(char **ptr_str_err_msg,
				int ret, char *input);
static int	msg_atof_too_large_input(char **ptr_str_err_msg);
static int	msg_atof_overflow_underflow(char **ptr_str_err_msg);
static int	msg_atof_wrong_input(char **ptr_str_err_msg);

/* to check
 *	first ft_strndup fail : DONE -> OK !
 *	ft_strdup fail : TO DO 
*/

int	init_msg_atof_failed(char **ptr_str_err_msg,
		int ret, char *input)
{
	if (ret == ATOF_SAFE_TOO_LARGE_INPUT)
		*ptr_str_err_msg = ft_strndup(input, 10);
	else
		*ptr_str_err_msg = ft_strdup(input);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_second("'", *ptr_str_err_msg);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	if (ret == ATOF_SAFE_TOO_LARGE_INPUT)
		return (msg_atof_too_large_input(ptr_str_err_msg));
	else if (ret == ATOF_SAFE_OVERFLOW || ret == ATOF_SAFE_UNDERFLOW)
		return (msg_atof_overflow_underflow(ptr_str_err_msg));
	else if (ret == ATOF_SAFE_WRONG_INPUT)
		return (msg_atof_wrong_input(ptr_str_err_msg));
	*ptr_str_err_msg = ft_strjoin_free_second("'", *ptr_str_err_msg);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	msg_atof_too_large_input(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"...': given value can not be converted to float"
			"input string is too big to get converted\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	msg_atof_overflow_underflow(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"': value can not be converted to double: "
			"will overflow / underflow\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	msg_atof_wrong_input(char **ptr_str_err_msg)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"': unexepected character while processing conversion\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}
