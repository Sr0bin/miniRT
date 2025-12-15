/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_add_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:19:23 by jweber            #+#    #+#             */
/*   Updated: 2025/11/03 11:20:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minirt.h"
#include "parsing.h"

/* to check
 *	fail_add_msg fail : DONE -> OK !
*/

int	fail_add_msg(const char *msg, int ret, char **ptr_str_err_msg)
{
	if (ret == FAILURE_PARSE_PERSONNALIZED)
	{
		*ptr_str_err_msg = ft_strjoin_free_second(msg, *ptr_str_err_msg);
		if (*ptr_str_err_msg == NULL)
			return (FAILURE_MALLOC);
	}
	return (ret);
}
