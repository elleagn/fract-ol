/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:14:13 by gozon             #+#    #+#             */
/*   Updated: 2024/09/16 17:13:00 by gozon            ###   ########.fr       */
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

unsigned int	get_pixel_color(t_pixel pixel, t_vars vars)
{
	int	it;

	it = calc_jmb(pixel.complex, vars.c, vars.iterations, vars.threshold);
	// if (it == vars.iterations)
	// 	return (0);
	// if (it < vars.iterations / 5)
	// 	return (0xfd00ff);
	// if (it < 2 * vars.iterations / 5)
	// 	return (0xfdff00);
	// if (it < 3 * vars.iterations / 5)
	// 	return (0x00ff38);
	// if (it < 4 * vars.iterations / 5)
	// 	return (0x00f9ff);
	return (it * 0x3c00ff);
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

void	color_image(t_img img, t_vars vars)
{
	t_pixel			pixel;
	unsigned int	color;

	pixel = init_first_pixel(img);
	while (pixel.coord_y < IMAGE_HEIGHT)
	{
		while (pixel.coord_x < IMAGE_WIDTH)
		{
			color = get_pixel_color(pixel, vars);
			image_pixel_put(img, pixel, color);
			pixel.coord_x += 1;
			pixel.complex.real += img.step;
		}
		pixel.coord_x = 0;
		pixel.complex.real = img.upper_left_corner.real;
		pixel.coord_y += 1;
		pixel.complex.imaginary -= img.step;
	}
}
