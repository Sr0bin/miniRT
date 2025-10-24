/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:27:22 by jweber            #+#    #+#             */
/*   Updated: 2025/10/24 16:53:39 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"

static int	parse_file(char *filename, t_vector *ptr_objects);
static int	get_each_objects(t_vector file_content, t_vector *ptr_objects);

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

static int	get_objects(t_vector file_content, t_vector *ptr_objets);

static int	parse_file(char *filename, t_vector *ptr_objects)
{
	t_vector	file_content;
	int			ret;

	ret = get_file_content(filename, &file_content);
	if (ret != 0)
		return (ret);
	ret = get_objects(file_content, ptr_objects);
	ft_vector_free(&file_content);
	if (ret != 0)
		return (ret);
	return (SUCCESS);
}

void	free_obj_vector(t_vector *ptr_vec);

static int	get_objects(t_vector file_content, t_vector *ptr_objects)
{
	int			ret;

	ret = ft_vector_init(ptr_objects, 10, sizeof(t_object), free_obj_vector);
	if (ret != SUCCESS)
		return (FAILURE_MALLOC);
	ret = get_each_objects(file_content, ptr_objects);
	if (ret != SUCCESS)
	{
		ft_vector_free(ptr_objects);
		return (ret);
	}
	return (SUCCESS);
}

static int	get_each_objects(t_vector file_content, t_vector *ptr_objects)
{
	size_t		i;
	char		**elements;
	int			ret;
	t_object	obj_tmp;

	i = 0;
	while (i < file_content.size)
	{
		elements = ft_split(((char **)file_content.data)[i], WHITE_SPACE);
		//TODO: change whitesaces by only " " to split only on spaces (it thinkg
		// it is ok to let splitting on whitespace -> to see with roro
		// but think to trim '\n' at the end of ((char **)file_content.data)[i] !
		if (elements == NULL)
			return (FAILURE_MALLOC);
		ret = fill_obj_content(&obj_tmp, elements);
		ft_split_free(elements);
		if (ret != 0)
			return (ret);
		ret = ft_vector_add_single(ptr_objects, &obj_tmp);
		if (ret != 0)
			return (ret);
		i++;
	}
	return (SUCCESS);
}

void	free_obj_vector(t_vector *ptr_vec)
{
	free(ptr_vec->data);
	ptr_vec->data = NULL;
	ptr_vec->data_size = 0;
	ptr_vec->size = 0;
	ptr_vec->capacity = 0;
}
