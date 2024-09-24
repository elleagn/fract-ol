/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:23:52 by gozon             #+#    #+#             */
/*   Updated: 2024/09/24 11:29:27 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_mlx	*init_mlx_struct(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (perror("malloc"), NULL);
	mlx->mlx = NULL;
	mlx->window = NULL;
	mlx->img.img = NULL;
	return (mlx);
}

int	close_window(void *mlx_void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)mlx_void;
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx);
	exit(0);
}

t_mlx	*create_window(void)
{
	t_mlx	*mlx;

	mlx = init_mlx_struct();
	if (!mlx)
		return (0);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (perror("mlx_init"), close_window(mlx), NULL);
	mlx->window = mlx_new_window(mlx->mlx, IMAGE_WIDTH, IMAGE_HEIGHT,
			"fract'ol");
	if (!mlx->window)
		return (perror("mlx_new_window"), close_window(mlx), NULL);
	return (mlx);
}
