/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:07:02 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 11:08:55 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_complex	calculate_ulc_zoom(int button, t_img img)
{
	t_complex	ulc;

	if (button == 4)
	{
		ulc.real = -(IMAGE_WIDTH / 2) * img.step / 1.2;
		ulc.imaginary = (IMAGE_HEIGHT / 2) * img.step / 1.2;
	}
	else
	{
		ulc.real = -(IMAGE_WIDTH / 2) * img.step / 0.8;
		ulc.imaginary = (IMAGE_HEIGHT / 2) * img.step / 0.8;
	}
	return (ulc);
}

int	handle_key(int keycode, void *params_void)
{
	t_mlx		*mlx;
	t_params	params;

	params = *(t_params *)params_void;
	mlx = params.mlx;
	if (keycode == ESC)
		close_window(mlx);
	return (0);
}

int	zoom(int button, int x, int y, void *params_void)
{
	t_mlx		*mlx;
	t_vars		vars;
	t_params	params;
	t_complex	new_ulc;

	(void)x;
	(void)y;
	params = *(t_params *)params_void;
	vars = params.vars;
	mlx = params.mlx;
	new_ulc = calculate_ulc_zoom(button, mlx->img);
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
