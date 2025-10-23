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

#include "ft_memory.h"
#include "ft_standard.h"
#include "ft_string.h"
#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"

static int	parse_file(char *filename, t_vector *ptr_objects);

int	parsing(int argc, char **argv, t_vector *ptr_objects)
{
	int	ret;

	ret = check_args(argc, argv);
	if (ret != SUCCESS)
		return (ret);
	ret = parse_file(argv[1], ptr_objects);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

static int	fill_tmp_struct_from(t_vector file_content, t_vector *ptr_objects);

static int	parse_file(char *filename, t_vector *ptr_objects)
{
	t_vector	file_content;
	int			ret;

	(void)ptr_objects;
	ret = get_file_content(filename, &file_content);
	if (ret != 0)
		return (ret);
	ret = fill_tmp_struct_from(file_content, ptr_objects);
	ft_vector_free(&file_content);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

static int	get_object_type(char *str);

static int	fill_tmp_struct_from(t_vector file_content, t_vector *ptr_objets)
{
	char		**elements;
	size_t		i;
	//t_object	obj_tmp;

	i = 0;
	(void) ptr_objets;
	while (i < file_content.size)
	{
		elements = ft_split(((char **)file_content.data)[i], WHITE_SPACE);
		if (elements == NULL)
			return (FAILURE_MALLOC);
		/*
		ret = fill_obj_content(&obj_tmp, elements);
		ft_bzero(&obj_tmp, sizeof(obj_tmp));
		obj_tmp.type = get_object_type(elements[0]);
		if (obj_tmp.type < 0) 
			return (FAILURE_PARSE_WRONG_OBJ_TYPE);
		*/
		(void) get_object_type;
		free(elements);
		/*
		if (ret != 0)
			return (ret);
		*/
		i++;
	}
	return (SUCCESS);
}

static int	get_object_type(char *str)
{
	if (ft_strcmp(str, "A") == 0)
		return (OBJ_AMBIENT);
	else if (ft_strcmp(str, "C") == 0)
		return (OBJ_CAMERA);
	else if (ft_strcmp(str, "L") == 0)
		return (OBJ_LIGHT);
	else if (ft_strcmp(str, "sp") == 0)
		return (OBJ_SPHERE);
	else if (ft_strcmp(str, "pl") == 0)
		return (OBJ_PLANE);
	else if (ft_strcmp(str, "cy") == 0)
		return (OBJ_CYLINDER);
	else
		return (-1);
}
