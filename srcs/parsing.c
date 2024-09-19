/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:39:19 by gozon             #+#    #+#             */
/*   Updated: 2024/09/19 15:23:27 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_vars	init_mandelbrot(char **argv)
{
	t_vars	vars;

	if (argv[0])
	{
		ft_printf("Mandelbrot set does not take any parameters.\n"
			"Try : ./fractol mandelbrot\n");
		vars.type = 0;
	}
	else
	{
		vars.iterations = 100;
		vars.threshold = 4;
		vars.type = 'm';
	}
	return (vars);
}

t_vars	init_julia(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 4)
	{
		vars.type = 0;
		ft_printf("Wrong number of arguments for julia set.\n"
			"Usage: ./fractol julia a b (a, b floats representing \n"
			"the parameter a + ib)\n");
	}
	else
}

t_vars	parsing(int argc, char **argv)
{
	t_vars	vars;

	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		vars = init_mandelbrot(&argv[2]);
	else if (!ft_strncmp(argv[1], "julia", 6))
		vars = init_julia(argc, &argv[2]);
	else
	{
		ft_printf("Fractal name unrecognized. Usage: \n"
			"./fractol mandelbrot\n"
			"./fractol julia a b (julia set of parameter a + ib)\n");
		vars.type = 0;
	}
	return (vars);
}
