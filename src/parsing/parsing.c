/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:27:22 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 12:46:44 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_standard.h"
#include "ft_string.h"
#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"
#include "object.h"

int	parsing(int argc, char **argv, t_scene *ptr_scene,
		char **ptr_str_err_msg)
{
	t_vector	objects;
	int			ret;
	t_vector	file_content;

	ret = check_args(argc, argv);
	if (ret != SUCCESS)
		return (ret);
	ret = get_file_content(argv[1], &file_content);
	if (ret != 0)
		return (ret);
	ret = parse_file_content(file_content, &objects, ptr_str_err_msg);
	ft_vector_free(&file_content);
	if (ret != 0)
		return (ret);
	ret = check_objects(&objects);
	if (ret != 0)
	{
		ft_vector_free(&objects);
		return (ret);
	}
	ret = scene_init(ptr_scene, &objects);
	ft_vector_free(&objects);
	if (ret != SUCCESS)
	{
		return (ret);
	}
	return (SUCCESS);
}

