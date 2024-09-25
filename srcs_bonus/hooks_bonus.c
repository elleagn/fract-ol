/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:07:02 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 10:39:12 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

int	handle_key(int keycode, void *params_void)
{
	t_mlx		*mlx;
	t_vars		vars;
	t_params	params;
	t_complex	ulc;

	params = *(t_params *)params_void;
	vars = params.vars;
	mlx = params.mlx;
	if (keycode == ESC)
		close_window(mlx);
	if (keycode >= LEFT_ARROW && keycode <= DOWN_ARROW)
	{
		ulc = translate_ulc(mlx->img, keycode);
		draw_fractal(mlx, vars, ulc, mlx->img.step);
	}
	return (0);
}

int	zoom(int button, int x, int y, void *params_void)
{
	t_mlx		*mlx;
	t_vars		vars;
	t_params	params;
	t_complex	new_ulc;

	params = *(t_params *)params_void;
	vars = params.vars;
	mlx = params.mlx;
	new_ulc = calculate_ulc_zoom(x, y, button, mlx->img);
	if (button == 4)
		draw_fractal(mlx, vars, new_ulc, mlx->img.step / 1.2);
	if (button == 5)
		draw_fractal(mlx, vars, new_ulc, mlx->img.step / 0.8);
	return (0);
}

void	mlx_hooks(t_params params)
{
	t_mlx	*mlx;

	mlx = params.mlx;
	mlx_hook(mlx->window, KEY_PRESS, 1l << 0, handle_key, &params);
	mlx_hook(mlx->window, BUTTON_PRESS, 1L << 2, zoom, &params);
	mlx_hook(mlx->window, DESTROY_NOTIFY, (1L << 17), close_window, mlx);
}
