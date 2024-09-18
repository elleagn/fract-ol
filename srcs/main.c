/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:39:52 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 13:26:10 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_mlx	*mlx;

	vars = parsing(argc, argv);
	if (vars.type == 0)
		return (1);
	mlx = create_window(vars);
	if (!mlx)
		return (1);
	draw_fractal(vars, mlx, 0);
	mlx_hooks(vars, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
