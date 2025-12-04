/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:51 by jweber            #+#    #+#             */
/*   Updated: 2025/12/04 13:49:09 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "graphics.h"
#include "minirt.h"
#include "mlx_setup.h"
#include "parsing.h"
#include "printing.h"
#include "vec3.h"
#include "object.h"
#include "render.h"
#include <stdio.h>

void	vector_test(void);

int	main(int argc, char **argv)
{
	t_scene		scene;
	int			ret;
	char		*str_err_msg;
	t_mlx		mlx;
	t_ray		*array_ray;

	str_err_msg = NULL;
	ret = parsing(argc, argv, &scene, &str_err_msg);
	if (ret != 0)
		return (print_error(ret, str_err_msg));
	print_objects(&scene);
	ret = mlx_setup(&mlx);
	if (ret != 0)
	{
		// print some error message !
		free_scene(&scene);
		return (ret);
	}
	print_mlx_stats(mlx);
	ret = render(&scene, &array_ray, mlx);
	if (ret != 0)
	{
		// print some error message !
		free_scene(&scene);
		mlx_free_all(&mlx);
		return (1);
	}
	fflush(stdout);
	mlx_start(&mlx);
	mlx_free_all(&mlx);
	free_rays(&array_ray, WINDOW_WIDTH * WINDOW_HEIGHT);
	free_scene(&scene);
	return (0);
}
