/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:39:19 by gozon             #+#    #+#             */
/*   Updated: 2024/09/19 14:58:12 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_vars	parsing(int argc, char **argv)
{
	t_vars	vars;

	if (!ft_strncmp(argv[1], "mandelbrot", 11))
		vars = init_mandelbrot(&argv[2]);
	else if (!ft_strncmp(argv[1], "julia", 6))
		vars = init_julia(&argv[2]);
	else
	{
		ft_printf("Fractal name unrecognized. Usage: \n"
			"./mandelbrot\n"
			"./julia a b (julia set of parameter a + ib)\n");
		return ()
	}
}
