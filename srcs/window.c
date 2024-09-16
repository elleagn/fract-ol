/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:23:52 by gozon             #+#    #+#             */
/*   Updated: 2024/09/16 17:18:10 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
	t_vars	vars;

	params[0] = mlx_init();
	params[1] = mlx_new_window(params[0], IMAGE_WIDTH, IMAGE_HEIGHT, "test");
	params[2] = mlx_new_image(params[0], IMAGE_WIDTH, IMAGE_HEIGHT);
	img.addr = mlx_get_data_addr(params[2], &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.upper_left_corner.real = -IMAGE_WIDTH / 200;
	img.upper_left_corner.imaginary = IMAGE_HEIGHT / 200;
	img.step = 0.01;
	vars.c.real = -0.8;
	vars.c.imaginary = 0.156;
	vars.threshold = 4;
	vars.iterations = 1000;
	color_image(img, vars);
	mlx_put_image_to_window(params[0], params[1], params[2], 0, 0);
	mlx_hook(params[1], 17, (1L << 17), close_window, params);
	mlx_loop(params[0]);
	return (0);
}
