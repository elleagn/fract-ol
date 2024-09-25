/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:35:36 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 09:42:53 by gozon            ###   ########.fr       */
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
			return (i + 1);
		zn = add_complex(multiply_complex(zn, zn), c);
		i++;
	}
	return (0);
}

int	calculate_burning_ship(t_complex c)
{
	t_complex	zn;
	int			i;
	t_complex	z2;

	i = 0;
	zn.real = 0;
	zn.imaginary = 0;
	c.imaginary = -c.imaginary;
	c.real = -c.real;
	while (i < ITERATIONS)
	{
		if (mod_square(zn) > 200)
			return (i + 1);
		z2.real = pow(ft_abs(zn.real), 2) - pow(ft_abs(zn.imaginary), 2);
		z2.imaginary = 2 * ft_abs(zn.real) * ft_abs(zn.imaginary);
		zn = add_complex(z2, c);
		i++;
	}
	return (0);
}

int	calculate_birds_of_prey(t_complex c)
{
	t_complex	zn;
	int			i;
	t_complex	z3;

	i = 0;
	zn.real = 0;
	zn.imaginary = 0;
	while (i < ITERATIONS)
	{
		if (mod_square(zn) > 200)
			return (i + 1);
		z3.real = pow(ft_abs(zn.real), 3)
			- 3 * ft_abs(zn.real) * pow(ft_abs(zn.imaginary), 2);
		z3.imaginary = 3 * pow(ft_abs(zn.real), 2) * ft_abs(zn.imaginary)
			- pow(ft_abs(zn.imaginary), 3);
		zn = add_complex(z3, c);
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
