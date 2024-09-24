/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:44:33 by gozon             #+#    #+#             */
/*   Updated: 2024/09/23 14:38:30 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	affine(int color1, int color2, int interval, int it)
{
	double	res;
	int		color;

	res = color1 + color2 * (5 * it / (double)ITERATIONS - interval);
	color = (int)round(res);
	return (color);
}
