/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:49:54 by jweber            #+#    #+#             */
/*   Updated: 2025/11/27 18:31:23 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "matrix.h"
#include "minirt.h"
#include "parsing.h"
#include "vec3.h"

int			fill_direction(t_vec3 **ptr_to_ptr_direction,
				const char *direction, char **ptr_str_err_msg);
static int	fill_from_splitted_direction(t_vec3 **ptr_to_ptr_direction,
				char **splitted_direction, char **ptr_str_err_msg);
static int	direction_wrong_nb_args(char **ptr_str_err_msg,
				const char *direction_str);
static int	not_normed(char **ptr_str_err_msg, const char *direction_str);

int	fill_direction(t_vec3 **ptr_to_ptr_direction, const char *direction,
		char **ptr_str_err_msg)
{
	char	**splitted_direction;
	int		ret;

	splitted_direction = ft_split(direction, ",");
	if (splitted_direction == NULL)
		return (FAILURE_MALLOC);
	if (splitted_direction[0] == NULL || splitted_direction[1] == NULL
		|| splitted_direction[2] == NULL || splitted_direction[3] != NULL)
	{
		ft_split_free(splitted_direction);
		return (direction_wrong_nb_args(ptr_str_err_msg, direction));
	}
	ret = fill_from_splitted_direction(ptr_to_ptr_direction,
			splitted_direction, ptr_str_err_msg);
	ft_split_free(splitted_direction);
	if (ret != 0)
		return (ret);
	if (is_normed(**ptr_to_ptr_direction) == FALSE)
	{
		// free_matrix(*ptr_to_ptr_direction);
		return (not_normed(ptr_str_err_msg, direction));
	}
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

static int	direction_wrong_nb_args(char **ptr_str_err_msg,
				const char *direction_str)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, direction_str);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "': ");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			MSG_DIRECTION_WRONG_ARGUMENTS);
	if (ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}

static int	fill_from_splitted_direction(t_vec3 **ptr_to_ptr_direction,
				char **splitted_direction, char **ptr_str_err_msg)
{
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;
	int		ret;

	ret = ft_atof_safe(splitted_direction[0], &tmp_x);
	if (ret != 0)
		return (init_msg_atof_failed(ptr_str_err_msg, ret,
				splitted_direction[0]));
	ret = ft_atof_safe(splitted_direction[1], &tmp_y);
	if (ret != 0)
		return (init_msg_atof_failed(ptr_str_err_msg, ret,
				splitted_direction[1]));
	ret = ft_atof_safe(splitted_direction[2], &tmp_z);
	if (ret != 0)
		return (init_msg_atof_failed(ptr_str_err_msg, ret,
				splitted_direction[2]));
	*ptr_to_ptr_direction = vec3_alloc(tmp_x, tmp_y, tmp_z);
	if (*ptr_to_ptr_direction == NULL)
		return (FAILURE_MALLOC);
	return (SUCCESS);
}

static int	not_normed(char **ptr_str_err_msg, const char *direction_str)
{
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, "'");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg, direction_str);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	*ptr_str_err_msg = ft_strjoin_free_first(*ptr_str_err_msg,
			"': value are not normalized ! (sqrt(x^2 + y^2 + z^2) "
			"should equal 1)\n");
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (FAILURE_PARSE_PERSONNALIZED);
}
