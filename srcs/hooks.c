/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:07:02 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 17:18:43 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	zoom(int button, int x, int y, void **params)
{
	(void) x;
	(void) y;
	if (button == 4)
		draw_fractal((t_mlx *)params[0], *(t_vars *)params[1], 2);
	if (button == 5)
		draw_fractal((t_mlx *)params[0], *(t_vars *)params[1], 0.5);
	return (0);
}

void	mlx_hooks(t_mlx *mlx, t_vars vars)
{
	void	*params[2];

	params[0] = (void *)mlx;
	params[1] = (void *)&vars;
	mlx_hook(mlx->window, 4, 1L << 2, zoom, mlx);
	mlx_hook(mlx->window, DESTROY_NOTIFY, (1L << 17), close_window, mlx);
}
