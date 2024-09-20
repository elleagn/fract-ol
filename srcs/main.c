/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:39:52 by gozon             #+#    #+#             */
/*   Updated: 2024/09/20 11:58:14 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc < 2)
		return (ft_printf("Not enough arguments"), 0);
	params.vars = parsing(argc, argv);
	if (params.vars.type == 0)
		return (1);
	params.mlx = create_window();
	if (!params.mlx)
		return (1);
	draw_fractal(params.mlx, params.vars, 0);
	mlx_hooks(params);
	mlx_loop(params.mlx->mlx);
	return (0);
}
