/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:37:45 by gozon             #+#    #+#             */
/*   Updated: 2024/09/24 10:11:10 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_img(t_img *img, t_vars vars)
{
	img->upper_left_corner.imaginary = sqrt(vars.threshold);
	img->upper_left_corner.real = -IMAGE_WIDTH
		* img->upper_left_corner.imaginary / IMAGE_HEIGHT;
	img->step = -2 * img->upper_left_corner.real / IMAGE_WIDTH;
}

t_img	create_new_img(t_complex ulc, double step, t_mlx *mlx)
{
	t_img	img;

	img.img = mlx_new_image(mlx->mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	if (!img.img)
		return (perror("mlx_new_image"), close_window(mlx), img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	img.upper_left_corner = ulc;
	img.step = step;
	return (img);
}

void	draw_fractal(t_mlx *mlx, t_vars vars, t_complex ulc, double step)
{
	t_img	new_img;

	new_img = create_new_img(ulc, step, mlx);
	color_image(new_img, vars);
	mlx_put_image_to_window(mlx->mlx, mlx->window, new_img.img, 0, 0);
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx->img = new_img;
}
