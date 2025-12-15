/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:51 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 12:57:23 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "minirt.h"
#include "mlx_setup.h"
#include "parsing.h"
#include "printing.h"
#include "object.h"
#include "render.h"
#include <stdio.h>

static int	mlx_setup_failed(int ret, t_scene *ptr_scene);
static int	render_failed(int ret, t_scene *ptr_scene, t_mlx *ptr_mlx);

/* to check :
 *	parsing fail : DONE -> OK !
 *	mlx_setup fail : DONE -> OK !
 *	render fail : TO DO ;
*/

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
		return (mlx_setup_failed(ret, &scene));
	ret = render(&scene, &array_ray, mlx);
	if (ret != 0)
		return (render_failed(ret, &scene, &mlx));
	mlx_start(&mlx);
	mlx_free_all(&mlx);
	free_rays(&array_ray);
	free_scene(&scene);
	return (0);
}

static int	mlx_setup_failed(int ret, t_scene *ptr_scene)
{
	print_error(ret, NULL);
	free_scene(ptr_scene);
	return (FAILURE);
}

static int	render_failed(int ret, t_scene *ptr_scene, t_mlx *ptr_mlx)
{
	print_error(ret, NULL);
	free_scene(ptr_scene);
	mlx_free_all(ptr_mlx);
	return (FAILURE);
}
