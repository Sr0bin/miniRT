/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_consecutive_comma.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:19:20 by jweber            #+#    #+#             */
/*   Updated: 2025/12/15 11:20:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minirt.h"

int	check_consecutive_comma(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (TRUE);
		i++;
	}
	return (FALSE);
}
