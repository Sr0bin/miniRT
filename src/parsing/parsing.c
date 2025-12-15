/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:27:22 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 13:16:03 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"
#include "object.h"

/* to check
 *	check_args fail : DONE -> OK !
 *	get_file_content fail : DONE -> OK !
 *	parse_file_content fail : TO DO ;
 *	scene_init fail : TO DO ;
*/

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
	ret = scene_init(ptr_scene, &objects);
	ft_vector_free(&objects);
	if (ret != SUCCESS)
	{
		return (ret);
	}
	return (SUCCESS);
}
