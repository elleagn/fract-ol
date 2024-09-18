/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_julia_mb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:35:36 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 09:24:04 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	calc_jmb(t_complex z0, t_complex c, int its, double threshold)
{
	t_complex	zn;
	int			i;

	zn = z0;
	i = 0;
	while (i < its)
	{
		if (mod_square(zn) > threshold)
			return (i);
		zn = add_complex(multiply_complex(zn, zn), c);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_complex	z0;
// 	t_complex	c;
// 	t_vars		vars;
// 	double		res;

// 	z0.real = 1;
// 	z0.imaginary = 1;
// 	c.real = 1;
// 	c.imaginary = 1;
// 	vars.c = c;
// 	vars.threshold = 2;
// 	vars.iterations = 100;
// 	res = calculate_julia_mb(vars, z0);
// 	printf("%f", res);
// 	return (0);
// }
