/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:06:14 by rorollin          #+#    #+#             */
/*   Updated: 2025/12/12 11:31:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

int	solve_polynomial(t_polynomial *poly, double a, double b, double c)
{
	t_polynomial	temp;

	temp.a = a;
	temp.b = b;
	temp.c = c;
	temp.delta = (temp.b * temp.b) - (4 * temp.a * temp.c);
	*poly = temp;
	if (temp.delta < 0)
		return (0);
	if (fabs(temp.delta - 0) < 1e-5)
	{
		temp.t1 = (-b - sqrt(temp.delta)) / (2 * a);
		temp.t2 = (-b + sqrt(temp.delta)) / (2 * a);
		temp.t0 = (-b) / (2 * a);
		*poly = temp;
		return (1);
	}
	temp.t1 = (-b - sqrt(temp.delta)) / (2 * a);
	temp.t2 = (-b + sqrt(temp.delta)) / (2 * a);
	*poly = temp;
	return (2);
}
