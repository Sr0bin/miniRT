/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:06:16 by jweber            #+#    #+#             */
/*   Updated: 2025/10/28 18:10:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <stdlib.h>

#define WINDOW_HEIGHT 500
#define WINDOW_WIDTH 800

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_window;
	void	*mlx_img;
	char	*mlx_img_data;
	size_t	width;
	size_t	height;
	size_t	bbp;
	int		endian;
}	t_mlx;

#endif
