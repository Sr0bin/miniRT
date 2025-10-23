/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:41:41 by jweber            #+#    #+#             */
/*   Updated: 2025/10/23 19:09:31 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "parsing.h"
#include "printing.h"
#include "vector.h"

static void	vector_test(void)
{
	t_vec3	*a;
	t_vec3	*b;

	a = create_vector(1,0,0);
	b = create_vector(0,1,0);
	print_vector(a);
	print_vector(b);
	printf("Norm a:%f\n", vector_norm(*a));
	printf("Dot Product :%f\n", dot_product(*a,*b));
	print_vector(cross_product(*a, *b));
}

int	main(int argc, char **argv)
{
	t_vector	objects;
	int			ret;

	//vector_test();
	ret = parsing(argc, argv, &objects);
	if (ret != 0)
		return (print_error(ret));
}
