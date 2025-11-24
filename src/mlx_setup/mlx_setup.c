/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:58:11 by jweber            #+#    #+#             */
/*   Updated: 2025/11/04 10:33:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vectors.h"
#include "minirt.h"
#include "graphics.h"
#include "mlx_setup.h"
#include "mlx.h"

#define XK_MISCELLANY

#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

int	key_press(int key_code, void *params);
int	key_release(int key_code, void *params);

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
	mlx_hook(ptr_mlx->mlx_window, KeyPress, KeyPressMask,
		&key_press, ptr_mlx);
	mlx_hook(ptr_mlx->mlx_window, KeyRelease, KeyPressMask,
		&key_release, ptr_mlx);
	mlx_hook(ptr_mlx->mlx_window, DestroyNotify, NoEventMask,
		&mlx_loop_end, ptr_mlx->mlx_ptr);
	mlx_loop(ptr_mlx->mlx_ptr);
	return (SUCCESS);
}

int	key_press(int key_code, void *params)
{
	if (key_code == XK_Escape)
		mlx_loop_end(((t_mlx *)params)->mlx_ptr);
	return (0);
}

int	key_release(int key_code, void *params)
{
	(void) key_code;
	(void) params;
	return (0);
}
