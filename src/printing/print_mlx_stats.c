/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mlx_stats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:05:43 by jweber            #+#    #+#             */
/*   Updated: 2025/11/27 11:09:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "printing.h"

void	print_mlx_stats(t_mlx mlx)
{
	printf("mlx.bpp = %i\n", mlx.bpp);
	printf("mlx.line_size = %i\n", mlx.line_size);
	printf("mlx.endian = %i\n", mlx.endian);
	return ;
}
