/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:02:21 by jweber            #+#    #+#             */
/*   Updated: 2025/11/04 10:33:05 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_SETUP_H
# define MLX_SETUP_H

# include "graphics.h"

int		mlx_setup(t_mlx *ptr_mlx);
void	mlx_free_all(t_mlx *ptr_mlx);

#endif
