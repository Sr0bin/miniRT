/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:24:56 by jweber            #+#    #+#             */
/*   Updated: 2025/10/21 15:26:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "printing.h"
#include "ft_io.h"

int	print_error(void)
{
	ft_putstr_fd("error\n", 2);
	return (FAILURE);
}
