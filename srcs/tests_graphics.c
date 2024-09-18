/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:09:02 by gozon             #+#    #+#             */
/*   Updated: 2024/09/18 11:06:43 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_pixel	init_first_pixel(t_img img)
{
	t_pixel	pixel;

	pixel.complex = img.upper_left_corner;
	pixel.coord_x = 0;
	pixel.coord_y = 0;
	return (pixel);
}

void	image_pixel_put(t_img img, t_pixel pixel, unsigned int color)
{
	char	*address;
	int		x;
	int		y;

	x = pixel.coord_x;
	y = pixel.coord_y;
	address = img.addr + y * img.line_length + x * (img.bits_per_pixel / 8);
	*(unsigned int *)address = color;
}

void	color_image(t_img img)
{
	t_pixel			pixel;
//	double			mod;

	pixel = init_first_pixel(img);
	while (pixel.coord_y < IMAGE_HEIGHT)
	{
		while (pixel.coord_x < IMAGE_WIDTH)
		{
			if (mod_square(pixel.complex) < 10 * img.step)
				image_pixel_put(img, pixel, COLOR);
			pixel.coord_x += 1;
			pixel.complex.real += img.step;
		}
		pixel.coord_x = 0;
		pixel.complex.real = img.upper_left_corner.real;
		pixel.coord_y += 1;
		pixel.complex.imaginary -= img.step;
	}
}

int	close_window(void **param)
{
	mlx_destroy_image(param[0], param[2]);
	mlx_destroy_window(param[0], param[1]);
	mlx_destroy_display(param[0]);
	free(param[0]);
	exit(0);
}

int	main(void)
{
	void	*params[3];
	t_img	img;

	params[0] = mlx_init();
	params[1] = mlx_new_window(params[0], IMAGE_WIDTH, IMAGE_HEIGHT, "test");
	params[2] = mlx_new_image(params[0], IMAGE_WIDTH, IMAGE_HEIGHT);
	img.addr = mlx_get_data_addr(params[2], &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.upper_left_corner.real = -IMAGE_WIDTH / 2000.0;
	img.upper_left_corner.imaginary = IMAGE_HEIGHT / 2000.0;
	img.step = 0.001;
	color_image(img);
	mlx_put_image_to_window(params[0], params[1], params[2], 0, 0);
	mlx_hook(params[1], 17, (1L << 17), close_window, params);
	mlx_loop(params[0]);
	return (0);
}
