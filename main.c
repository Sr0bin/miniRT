/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:51 by jweber            #+#    #+#             */
/*   Updated: 2025/12/02 16:01:52 by rorollin         ###   ########lyon.fr   */
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

int	print_sphere(t_object obj);
int	print_camera(t_object obj);
int	main(int argc, char **argv)
{
	t_vector	objects;
	t_scene		scene;
	int			ret;
	char		*str_err_msg;
	t_mlx		mlx;
	t_ray		*array_ray;

	//vector_test();
	str_err_msg = NULL;
	ret = parsing(argc, argv, &objects, &str_err_msg);
	if (ret != 0)
		return (print_error(ret, str_err_msg));
	

	// print_camera(*search_object(&objects, OBJ_CAMERA, 0));
	// print_sphere(*search_object(&objects, OBJ_SPHERE, 1));
	ret = scene_init(&scene, &objects);
	if (ret != SUCCESS)
	{
		ft_vector_free(&objects);
		return (EXIT_FAILURE);
	}
	print_objects(scene.objects);
	// print_objects(objects);
	free_scene(&scene);
	ret = mlx_setup(&mlx);
	if (ret != 0)
	{
		ft_vector_free(&objects);
		return (ret);
	}
	/*
	printf("WINDOW_WIDTH * WINDOW_HEIGHT * 4 = %i\n", WINDOW_HEIGHT * WINDOW_WIDTH * 4);
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT * 4;)
	{
		printf("pixel[%i + 0] = %i\n", i / 4, mlx.mlx_img_data[i + 0]);
		printf("pixel[%i + 1] = %i\n", i / 4, mlx.mlx_img_data[i + 1]);
		printf("pixel[%i + 2] = %i\n", i / 4, mlx.mlx_img_data[i + 2]);
		printf("pixel[%i + 3] = %i\n", i / 4, mlx.mlx_img_data[i + 3]);
		i += 4;
	}
	*/
	print_mlx_stats(mlx);
	fflush(stdout);
	ret = render(objects, &array_ray, mlx);
	if (ret != 0)
	{
		// do stuff
	}
	/*
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT * 4;)
	{
		printf("pixel[%i + 0] = %i\n", i / 4, mlx.mlx_img_data[i + 0]);
		printf("pixel[%i + 1] = %i\n", i / 4, mlx.mlx_img_data[i + 1]);
		printf("pixel[%i + 2] = %i\n", i / 4, mlx.mlx_img_data[i + 2]);
		printf("pixel[%i + 3] = %i\n", i / 4, mlx.mlx_img_data[i + 3]);
		i += 4;
	}
	*/
	fflush(stdout);
	mlx_start(&mlx);
	mlx_free_all(&mlx);
	free_rays(&array_ray, WINDOW_WIDTH * WINDOW_HEIGHT);
	ft_vector_free(&objects);
	return (0);
}

void	vector_test(void)
{
	t_vec3	*a;
	t_vec3	*b;

	a = vec3_alloc(-1, -1, 0);
	b = vec3_alloc(0, 1, 0);
	print_vector(a);
	print_vector(b);
	print_delimitor();
	printf("Norm a:%f\n", vector_norm3(*a));
	print_delimitor();
	printf("Dot Product :%f\n", dot_product3(*a,*b));
	// print_vector(cross_product(*a, *b));
	// print_vector(reflection_vector(*a, *b));
}
