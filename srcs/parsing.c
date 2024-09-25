/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:39:19 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 09:39:23 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_vars	init_mandelbrot(char **argv)
{
	t_vars	vars;

	if (argv[2])
	{
		ft_printf("Mandelbrot set does not take any parameters.\n");
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

int	valid_argument(char *arg)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if ((arg[i] == '+' || arg[i] == '-') && ft_isdigit(arg[i + 1]))
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if (arg[i] == '.' && !point)
				point = 1;
			else
				return (0);
		}
		i++;
	}
	return (i);
}

t_vars	init_julia(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 4)
	{
		vars.type = 0;
		ft_printf("Wrong number of arguments for julia set.\n");
	}
	else
	{
		if (!valid_argument(argv[2]) || !valid_argument(argv[3]))
		{
			vars.type = 0;
			ft_printf("Invalid arguments for julia set.\n");
		}
		else
		{
			vars.c = atocomplex(argv[2], argv[3]);
			vars.iterations = 1000;
			vars.threshold = choose_threshold(vars.c);
			vars.type = 'j';
		}
	}
	return (vars);
}

t_vars	parsing(int argc, char **argv)
{
	t_vars	vars;

	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		vars = init_mandelbrot(argv);
	else if (!ft_strncmp(argv[1], "burning_ship", 13))
		vars = init_burningship(argv);
	else if (!ft_strncmp(argv[1], "birds_of_prey", 14))
		vars = init_birdsofprey(argv);
	else if (!ft_strncmp(argv[1], "julia", 6))
		vars = init_julia(argc, argv);
	else
	{
		ft_printf("Fractal name unrecognized. Usage: \n"
			"./fractol mandelbrot\n"
			"./fractol julia a b (julia set of parameter a + ib)\n");
		vars.type = 0;
	}
	return (vars);
}
