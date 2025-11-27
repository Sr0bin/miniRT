/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:58:11 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 10:17:55 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "graphics.h"
#include "mlx_setup.h"
#include "mlx.h"

int	mlx_setup(t_mlx *ptr_mlx)
{
	ptr_mlx->mlx_ptr = mlx_init();
	if (ptr_mlx->mlx_ptr == NULL)
		return (FAILURE_MLX);
	ptr_mlx->mlx_window = mlx_new_window(ptr_mlx->mlx_ptr, 
			WINDOW_WIDTH, WINDOW_HEIGHT, (char *)"minirt");
	if (ptr_mlx->mlx_window == NULL)
	{
		mlx_destroy_display(ptr_mlx->mlx_ptr);
		free(ptr_mlx->mlx_ptr);
		return (FAILURE_MLX);
	}
	ptr_mlx->mlx_img = mlx_new_image(ptr_mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (ptr_mlx->mlx_img == NULL)
	{
		mlx_destroy_window(ptr_mlx->mlx_ptr, ptr_mlx->mlx_window);
		mlx_destroy_display(ptr_mlx->mlx_ptr);
		free(ptr_mlx->mlx_ptr);
		return (FAILURE_MLX);
	}
	ptr_mlx->mlx_img_data = mlx_get_data_addr(ptr_mlx->mlx_img,
			&ptr_mlx->bpp, &ptr_mlx->line_size, &ptr_mlx->endian);
	return (SUCCESS);
}
