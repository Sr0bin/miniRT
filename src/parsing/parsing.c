/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:27:22 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 14:10:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"

static int	parse_file_content(t_vector file_content, t_vector *ptr_objects,
				char **ptr_str_err_msg);

int	parsing(int argc, char **argv, t_vector *ptr_objects,
		char **ptr_str_err_msg)
{
	int			ret;
	t_vector	file_content;

	ret = check_args(argc, argv);
	if (ret != SUCCESS)
		return (ret);
	ret = get_file_content(argv[1], &file_content);
	if (ret != 0)
		return (ret);
	ret = parse_file_content(file_content, ptr_objects, ptr_str_err_msg);
	ft_vector_free(&file_content);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}


static int	get_each_objects(t_vector file_content, t_vector *ptr_objects,
				char **ptr_str_err_msg);

static int	parse_file_content(t_vector file_content, t_vector *ptr_objects,
				char **ptr_str_err_msg)
{
	int	ret;

	ret = ft_vector_init(ptr_objects, 10, sizeof(t_object), free_obj_vector);
	if (ret != SUCCESS)
		return (FAILURE_MALLOC);
	ret = get_each_objects(file_content, ptr_objects, ptr_str_err_msg);
	if (ret != SUCCESS)
		ft_vector_free(ptr_objects);
	return (ret);
}

int	append_line_nbr_content(t_line line, char **ptr_str_err_msg, int ret_val);

static int	get_each_objects(t_vector file_content, t_vector *ptr_objects,
				char **ptr_str_err_msg)
{
	size_t		i;
	char		**elements;
	int			ret;
	t_object	obj_tmp;

	i = 0;
	while (i < file_content.size)
	{
		elements = ft_split(((t_line *)file_content.data)[i].content, WHITE_SPACE);
		//TODO: change whitesaces by only " " to split only on spaces (it thinkg
		// it is ok to let splitting on whitespace -> to see with roro
		// but think to trim '\n' at the end of ((char **)file_content.data)[i] !
		// or no ?
		if (elements == NULL)
			return (FAILURE_MALLOC);
		ret = fill_obj_content(&obj_tmp, elements, ptr_str_err_msg);
		ft_split_free(elements);
		if (ret != 0)
		{
			if (ret == FAILURE_PARSE_PERSONNALIZED)
			{
				return (append_line_nbr_content(((t_line *)file_content.data)[i],
						ptr_str_err_msg, ret));
				/*
				*ptr_str_err_msg = ft_strjoin_free_second(
						"line [LINE_NUMBER] : [LINE_CONTENT]\n",
						*ptr_str_err_msg);
				if (*ptr_str_err_msg == NULL)
					return (FAILURE_MALLOC);
				*/
			}
			return (ret);
		}
		ret = ft_vector_add_single(ptr_objects, &obj_tmp);
		if (ret != 0)
			return (ret);
		i++;
	}
	return (SUCCESS);
}

int	append_line_nbr_content(t_line line, char **ptr_str_err_msg, int ret_val)
{
	char	*line_nbr;
	char	*tmp_line;

	tmp_line = ft_strdup("error line ");
	if (tmp_line == NULL)
		return (FAILURE_MALLOC);
	line_nbr = ft_itoa((int)line.line_nbr);
	if (line_nbr == NULL)
	{
		free(*ptr_str_err_msg);
		free(tmp_line);
		return (FAILURE_MALLOC);
	}
	tmp_line = ft_strjoin_free_first(tmp_line, line_nbr);
	free(line_nbr);
	if (tmp_line == NULL)
	{
		free(ptr_str_err_msg);
		return (FAILURE_MALLOC);
	}
	tmp_line = ft_strjoin_free_first(tmp_line, " : ");
	if (tmp_line == NULL)
		return (FAILURE_MALLOC);
	tmp_line = ft_strjoin_free_first(tmp_line, line.content);
	if (tmp_line == NULL)
	{
		return (FAILURE_MALLOC);
	}
	*ptr_str_err_msg = ft_strjoin_free_second(tmp_line, *ptr_str_err_msg);
	free(tmp_line);
	if (*ptr_str_err_msg == NULL)
		return (FAILURE_MALLOC);
	return (ret_val);
}
