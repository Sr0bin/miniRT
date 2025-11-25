/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:17:12 by jweber            #+#    #+#             */
/*   Updated: 2025/11/25 10:17:46 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_setup.h"
#include "mlx.h"

#define XK_MISCELLANY

#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

static int	key_press(int key_code, void *params);
static int	key_release(int key_code, void *params);

void	mlx_start(t_mlx *ptr_mlx)
{
	mlx_put_image_to_window(ptr_mlx->mlx_ptr,
		ptr_mlx->mlx_window, ptr_mlx->mlx_img, 0, 0);
	mlx_hook(ptr_mlx->mlx_window, KeyPress, KeyPressMask,
		&key_press, ptr_mlx);
	mlx_hook(ptr_mlx->mlx_window, KeyRelease, KeyPressMask,
		&key_release, ptr_mlx);
	mlx_hook(ptr_mlx->mlx_window, DestroyNotify, NoEventMask,
		&mlx_loop_end, ptr_mlx->mlx_ptr);
	mlx_loop(ptr_mlx->mlx_ptr);
	return ;
}

static int	key_press(int key_code, void *params)
{
	if (key_code == XK_Escape)
		mlx_loop_end(((t_mlx *)params)->mlx_ptr);
	return (0);
}

static int	key_release(int key_code, void *params)
{
	(void) key_code;
	(void) params;
	return (0);
}
