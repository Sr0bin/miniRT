/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:47:51 by jweber            #+#    #+#             */
/*   Updated: 2025/10/29 16:48:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"
#include "printing.h"
#include "vector.h"

void	vector_test(void);

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

int	main(int argc, char **argv)
{
	t_vector	objects;
	int			ret;
	char		*str_err_msg;

	//vector_test();
	str_err_msg = NULL;
	ret = parsing(argc, argv, &objects, &str_err_msg);
	if (ret != 0)
		return (print_error(ret, str_err_msg));
	print_objects(objects);
	ft_vector_free(&objects);
}
