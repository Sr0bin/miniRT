/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:06:16 by jweber            #+#    #+#             */
/*   Updated: 2025/12/08 13:41:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdlib.h>

# define WINDOW_WIDTH 1001
# define WINDOW_HEIGHT 1001
# if WINDOW_HEIGHT <= 4
#  error WINDOW_HEIGHT must be greater than 0
# endif
# if WINDOW_WIDTH <= 4
#  error WINDOW_WIDTH must be greater than 0
# endif

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*mlx_img;
	char	*mlx_img_data;
	size_t	width;
	size_t	height;
	int		line_size;
	int		bpp;
	int		endian;
}	t_mlx;

#endif
