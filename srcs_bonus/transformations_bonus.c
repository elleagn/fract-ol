/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:50:08 by gozon             #+#    #+#             */
/*   Updated: 2024/09/25 10:39:15 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol_bonus.h>

t_complex	coord_to_complex(int x, int y, t_img img)
{
	t_complex	complex;

	complex.real = img.upper_left_corner.real + x * img.step;
	complex.imaginary = img.upper_left_corner.imaginary - y * img.step;
	return (complex);
}

t_complex	calculate_ulc_zoom(int x, int y, int button, t_img img)
{
	t_complex	ulc;
	t_complex	mousepoint;

	mousepoint = coord_to_complex(x, y, img);
	if (button == 4)
	{
		ulc.real = mousepoint.real - x * img.step / 1.2;
		ulc.imaginary = mousepoint.imaginary + y * img.step / 1.2;
	}
	else
	{
		ulc.real = mousepoint.real - x * img.step / 0.8;
		ulc.imaginary = mousepoint.imaginary + y * img.step / 0.8;
	}
	return (ulc);
}

t_complex	translate_ulc(t_img img, int keycode)
{
	t_complex	ulc;

	if (keycode == LEFT_ARROW)
	{
		ulc.real = img.upper_left_corner.real - 10 * img.step;
		ulc.imaginary = img.upper_left_corner.imaginary;
	}
	else if (keycode == UP_ARROW)
	{
		ulc.real = img.upper_left_corner.real;
		ulc.imaginary = img.upper_left_corner.imaginary + 10 * img.step;
	}
	else if (keycode == RIGHT_ARROW)
	{
		ulc.real = img.upper_left_corner.real + 10 * img.step;
		ulc.imaginary = img.upper_left_corner.imaginary;
	}
	else
	{
		ulc.real = img.upper_left_corner.real;
		ulc.imaginary = img.upper_left_corner.imaginary - 10 * img.step;
	}
	return (ulc);
}
