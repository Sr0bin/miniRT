/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:55:22 by jweber            #+#    #+#             */
/*   Updated: 2025/11/03 16:03:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "minirt.h"
#include "parsing.h"

static int	fill_from_splitted_coo(t_point **ptr_to_ptr_coo,
				char **splitted_coo, char **ptr_str_err_msg);
static int	coordinates_wrong_nb_args(char **ptr_str_err_msg,
				const char *coo_str);

int	fill_coordinates(t_point **ptr_to_ptr_coo, const char *coo,
		char **ptr_str_err_msg)
{
	char	**splitted_coo;
	int		ret;

	splitted_coo = ft_split(coo, ",");
	if (splitted_coo == NULL)
		return (FAILURE_MALLOC);
	if (splitted_coo[0] == NULL || splitted_coo [1] == NULL
		|| splitted_coo [2] == NULL || splitted_coo[3] != NULL)
	{
		ft_split_free(splitted_coo);
		return (coordinates_wrong_nb_args(ptr_str_err_msg, coo));
	}
	ret = fill_from_splitted_coo(ptr_to_ptr_coo, splitted_coo, ptr_str_err_msg);
	ft_split_free(splitted_coo);
	return (ret);
}

static int	coordinates_wrong_nb_args(char **ptr_str_err_msg,
				const char *coo_str)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, coo_str);
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

static int	fill_from_splitted_coo(t_point **ptr_to_ptr_coo,
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
	*ptr_to_ptr_coo = create_point(tmp_x, tmp_y, tmp_z);
	if (*ptr_to_ptr_coo == NULL)
		return (FAILURE_MALLOC);
	return (SUCCESS);
}
