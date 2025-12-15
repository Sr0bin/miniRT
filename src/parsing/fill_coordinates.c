/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:55:22 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 11:33:02 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "minirt.h"
#include "parsing.h"

static int	fill_from_splitted_coo(t_point3 *ptr_coo,
				char **splitted_coo, char **ptr_str_err_msg);
static int	coordinates_wrong_nb_args(char **ptr_str_err_msg,
				const char *coo_str);

/* to check
 *	check_consecutive_comma fail : DONE -> OK !
 *	ft_split fail : DONE -> OK !
 *	wrong nb splitted coo : DONE -> OK !
 *	coordinates_wrong_nb_args fail : DONE -> OK !
 *	fill_from_splitted_coo fail : DONE -> OK !
*/

int	fill_coordinates(t_point3 *ptr_coordinates, const char *coordinates_str,
		char **ptr_str_err_msg)
{
	char	**splitted_coo;
	int		ret;
	int		consecutive_comma;

	consecutive_comma = check_consecutive_comma(coordinates_str);
	if (consecutive_comma == TRUE)
		return (coordinates_wrong_nb_args(ptr_str_err_msg, coordinates_str));
	splitted_coo = ft_split(coordinates_str, ",");
	if (splitted_coo == NULL)
		return (FAILURE_MALLOC);
	if (splitted_coo[0] == NULL || splitted_coo [1] == NULL
		|| splitted_coo [2] == NULL || splitted_coo[3] != NULL)
	{
		ft_split_free(splitted_coo);
		return (coordinates_wrong_nb_args(ptr_str_err_msg, coordinates_str));
	}
	ret = fill_from_splitted_coo(ptr_coordinates,
			splitted_coo, ptr_str_err_msg);
	ft_split_free(splitted_coo);
	return (ret);
}


static int	coordinates_wrong_nb_args(char **ptr_str_err_msg,
				const char *coordinates_str)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, coordinates_str);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "': ");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			MSG_COORDINATES_WRONG_ARGUMENTS);
	if (ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

/* to check
 *	all good no memory allocation
*/

static int	fill_from_splitted_coo(t_point3 *ptr_coo,
				char **splitted_coo, char **ptr_str_err_msg)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;
	int		ret;

	ret = ft_atof_safe(splitted_coo[0], &tmp_x);
	if (ret != SUCCESS)
		return (init_msg_atof_failed(ptr_str_err_msg, ret, splitted_coo[0]));
	ret = ft_atof_safe(splitted_coo[1], &tmp_y);
	if (ret != SUCCESS)
		return (init_msg_atof_failed(ptr_str_err_msg, ret, splitted_coo[1]));
	ret = ft_atof_safe(splitted_coo[2], &tmp_z);
	if (ret != SUCCESS)
		return (init_msg_atof_failed(ptr_str_err_msg, ret, splitted_coo[2]));
	*ptr_coo = point3_set_all(tmp_x, tmp_y, tmp_z);
	return (SUCCESS);
}
