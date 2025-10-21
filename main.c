/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:41:41 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 16:09:22 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "printing.h"

int	main(int argc, char **argv)
{
	t_tmp_struct	tmp_struct;

	if (parsing(argc, argv, &tmp_struct) != SUCCESS)
	{
		return (print_error());
	}
}
