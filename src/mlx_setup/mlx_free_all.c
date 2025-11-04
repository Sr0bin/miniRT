/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_free_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:35:01 by jweber            #+#    #+#             */
/*   Updated: 2025/11/04 10:35:55 by jweber           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "mlx_setup.h"
#include "mlx.h"

void	mlx_free_all(t_mlx *ptr_mlx)
{
	mlx_destroy_image(ptr_mlx->mlx_ptr, ptr_mlx->mlx_img);
	mlx_destroy_window(ptr_mlx->mlx_ptr, ptr_mlx->mlx_window);
	mlx_destroy_display(ptr_mlx->mlx_ptr);
	free(ptr_mlx->mlx_ptr);
}
