/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia_mb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:35:36 by gozon             #+#    #+#             */
/*   Updated: 2024/09/13 10:52:24 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

double	calculate_julia_mb(t_vars vars, t_complex z0)
{
	t_complex	zn;
	int			i;

	zn = z0;
	while (i < vars.iterations)
	{
		if (mod_square(zn) > vars.threshold_square)
			return (0);
		zn = add_complex(multiply_complex(zn, zn), vars.c);
		i++;
	}
	return (mod_square(zn));
}
