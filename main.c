/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:51 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 10:19:10 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "graphics.h"
#include "mlx_setup.h"
#include "parsing.h"
#include "printing.h"
#include "vector.h"
#include "render.h"

void	vector_test(void);

int	main(int argc, char **argv)
{
	t_vector	objects;
	int			ret;
	char		*str_err_msg;
	t_mlx		mlx;
	t_ray		*array_ray;

	//vector_test();
	str_err_msg = NULL;
	ret = parsing(argc, argv, &objects, &str_err_msg);
	if (ret != 0)
		return (print_error(ret, str_err_msg));
	print_objects(objects);
	ret = mlx_setup(&mlx);
	if (ret != 0)
	{
		ft_vector_free(&objects);
		return (ret);
	}
	ret = render(objects, &array_ray, mlx);
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

	a = create_vector(-1, -1, 0);
	b = create_vector(0, 1, 0);
	print_vector(a);
	print_vector(b);
	print_delimitor();
	printf("Norm a:%f\n", vector_norm(*a));
	print_delimitor();
	printf("Dot Product :%f\n", dot_product(*a,*b));
	print_vector(cross_product(*a, *b));
	print_vector(reflection_vector(*a, *b));
}
