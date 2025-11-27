/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:51 by jweber            #+#    #+#             */
/*   Updated: 2025/11/27 18:30:52 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "graphics.h"
#include "minirt.h"
#include "mlx_setup.h"
#include "parsing.h"
#include "printing.h"
#include "vector.h"
#include "object.h"

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
	// t_ray		*array_ray;

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
	// init_rays(mlx, &array_ray);
	mlx_free_all(&mlx);
	// render(objects, array_ray, mlx)
	// mlx_start(&mlx);
	ft_vector_free(&objects);
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
	printf("Norm a:%f\n", vector_norm(*a));
	print_delimitor();
	printf("Dot Product :%f\n", dot_product(*a,*b));
	// print_vector(cross_product(*a, *b));
	// print_vector(reflection_vector(*a, *b));
}
