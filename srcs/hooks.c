/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:07:02 by gozon             #+#    #+#             */
/*   Updated: 2024/09/24 09:32:07 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	zoom(int button, int x, int y, void *params_void)
{
	t_mlx		*mlx;
	t_vars		vars;
	t_params	params;

	(void)x;
	(void)y;
	params = *(t_params *)params_void;
	vars = params.vars;
	mlx = params.mlx;
	if (button == 4)
		draw_fractal(mlx, vars, 1.2);
	if (button == 5)
		draw_fractal(mlx, vars, 0.8);
	return (0);
}

void	mlx_hooks(t_params params)
{
	t_mlx	*mlx;

	mlx = params.mlx;
	mlx_hook(mlx->window, 4, 1L << 2, zoom, &params);
	mlx_hook(mlx->window, DESTROY_NOTIFY, (1L << 17), close_window, mlx);
}
