/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:39:19 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 11:50:54 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	parsing_error(t_vars *vars)
{
	ft_printf("Wrong argument format. Usage:\n"
		"./fractol mandelbrot\n"
		"./fractol julia a b (julia set of parameter a + ib)\n"
		);
	if (vars)
		vars->type = 0;
}

t_vars	init_mandelbrot(char **argv)
{
	t_vars	vars;

	if (argv[2])
		parsing_error(&vars);
	else
	{
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
		parsing_error(&vars);
	else
	{
		if (!valid_argument(argv[2]) || !valid_argument(argv[3]))
			parsing_error(&vars);
		else
		{
			vars.c = atocomplex(argv[2], argv[3]);
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
	else if (!ft_strncmp(argv[1], "julia", 6))
		vars = init_julia(argc, argv);
	else
		parsing_error(&vars);
	return (vars);
}
