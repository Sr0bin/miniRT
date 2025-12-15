/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:10:23 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 13:28:36 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"
#include "ft_standard.h"
#include "ft_string.h"

static int	get_each_objects(t_vector file_content, t_vector *ptr_objects,
				char **ptr_str_err_msg);
static int	parse_each_line(t_line line_i, t_vector *ptr_objects,
				char **ptr_str_err_msg);
static int	append_line_nbr_content(t_line line, char **ptr_str_err_msg,
				int ret_val);
static int	get_tmp_line(t_line line, char **ptr_tmp_line);

/* to check
 *	ft_vector_init fail : DONE -> OK !
 *	get_each_objects fail : DONE -> OK 
 *	check_object fail : DONE -> OK !
*/

int	parse_file_content(t_vector file_content, t_vector *ptr_objects,
				char **ptr_str_err_msg)
{
	int	ret;

	ret = ft_vector_init(ptr_objects, 10, sizeof(t_object), free_obj_vector);
	if (ret != SUCCESS)
		return (FAILURE_MALLOC);
	ret = get_each_objects(file_content, ptr_objects, ptr_str_err_msg);
	if (ret != SUCCESS)
	{
		ft_vector_free(ptr_objects);
		return (ret);
	}
	ret = check_objects(ptr_objects);
	if (ret != 0)
	{
		ft_vector_free(ptr_objects);
		return (ret);
	}
	return (ret);
}

/* to check
 *	parse_each_line fail : DONE -> OK !
*/

static int	get_each_objects(t_vector file_content, t_vector *ptr_objects,
				char **ptr_str_err_msg)
{
	size_t		i;
	int			ret;

	i = 0;
	while (i < file_content.size)
	{
		ret = parse_each_line(((t_line *)file_content.data)[i],
				ptr_objects, ptr_str_err_msg);
		if (ret != SUCCESS)
			return (ret);
		i++;
	}
	return (SUCCESS);
}

/* to check
 *	ft_split fail : DONE -> OK !
 *	fill_obj_content : DONE -> OK !
 *	append_line_nbr_content fail : DONE -> OK !
 *	ft_vector_add_single fail : DONE -> OK !
*/

static int	parse_each_line(t_line line_i, t_vector *ptr_objects,
				char **ptr_str_err_msg)
{
	char		**elements;
	int			ret;
	t_object	obj_tmp;

	elements = ft_split(line_i.content, WHITE_SPACE);
	if (elements == NULL)
		return (FAILURE_MALLOC);
	ret = fill_obj_content(&obj_tmp, elements, ptr_str_err_msg);
	ft_split_free(elements);
	if (ret != SUCCESS)
	{
		if (ret == FAILURE_PARSE_PERSONNALIZED)
		{
			return (append_line_nbr_content(line_i, ptr_str_err_msg, ret));
		}
		return (ret);
	}
	ret = ft_vector_add_single(ptr_objects, &obj_tmp);
	if (ret != SUCCESS)
		return (FAILURE_MALLOC);
	return (SUCCESS);
}

/* to check
 *	get_tmp_line fail : DONE -> OK !
 *	ft_strjoin_free_second fail : DONE -> OK !
*/

int	append_line_nbr_content(t_line line, char **ptr_str_err_msg, int ret_val)
{
	char	*tmp_line;
	int		ret;

	ret = get_tmp_line(line, &tmp_line);
	if (ret != SUCCESS)
	{
		free(*ptr_str_err_msg);
		return (ret);
	}
	*ptr_str_err_msg = ft_strjoin_free_second(tmp_line, *ptr_str_err_msg);
	free(tmp_line);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (ret_val);
}

/* to check
 *	ft_strdup fail : DONE -> OK !
 *	ft_itoa fail : DONE -> OK !
 *	first ft_strjoin_free_first fail : DONE -> OK !
 *	second ft_strjoin_free_first fail : DONE -> OK !
 *	third ft_strjoin_free_first fail : DONE -> OK !
*/

static int	get_tmp_line(t_line line, char **ptr_tmp_line)
{
	char	*line_nbr;

	*ptr_tmp_line = ft_strdup("error line ");
	if (*ptr_tmp_line == NULL)
		return (FAILURE_MALLOC);
	line_nbr = ft_itoa((int)line.line_nbr);
	if (line_nbr == NULL)
	{
		free(*ptr_tmp_line);
		return (FAILURE_MALLOC);
	}
	*ptr_tmp_line = ft_strjoin_free_first(*ptr_tmp_line, line_nbr);
	free(line_nbr);
	if (*ptr_tmp_line == NULL)
		return (FAILURE_MALLOC);
	*ptr_tmp_line = ft_strjoin_free_first(*ptr_tmp_line, ": ");
	if (*ptr_tmp_line == NULL)
		return (FAILURE_MALLOC);
	*ptr_tmp_line = ft_strjoin_free_first(*ptr_tmp_line, line.content);
	if (*ptr_tmp_line == NULL)
		return (FAILURE_MALLOC);
	return (SUCCESS);
}
