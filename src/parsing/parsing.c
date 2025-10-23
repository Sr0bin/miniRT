/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:27:22 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 16:43:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"
#include <stdio.h>

static int	parse_file(char *filename, t_tmp_struct	*ptr_tmp_struct);

int	parsing(int argc, char **argv, t_tmp_struct *ptr_tmp_struct)
{
	int	ret;

	ret = check_args(argc, argv);
	if (ret != SUCCESS)
		return (ret);
	ret = parse_file(argv[1], ptr_tmp_struct);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

static int	parse_file(char *filename, t_tmp_struct	*ptr_tmp_struct)
{
	t_vector	file_content;
	int			ret;

	(void)ptr_tmp_struct;
	ret = get_file_content(filename, &file_content);
	if (ret != 0)
		return (ret);
	/*
	ret = fill_tmp_struct_from(file_content, ptr_tmp_struct)
	return (ret);
	*/
	return (SUCCESS);
}
